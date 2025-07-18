/**
 * @file plugin_info.h
 * @brief Common Tesseract Plugin Infos
 *
 * @author Levi Armstrong
 * @date January 18, 2018
 * @version TODO
 * @bug No known bugs
 *
 * @copyright Copyright (c) 2017, Southwest Research Institute
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef TESSERACT_COMMON_PLUGIN_INFO_H
#define TESSERACT_COMMON_PLUGIN_INFO_H

#include <tesseract_common/macros.h>
TESSERACT_COMMON_IGNORE_WARNINGS_PUSH
#include <boost/serialization/export.hpp>
#include <Eigen/Core>
#include <map>
#include <yaml-cpp/yaml.h>
TESSERACT_COMMON_IGNORE_WARNINGS_POP

#include <tesseract_common/eigen_types.h>

namespace boost::serialization
{
class access;
}

namespace tesseract_common
{
struct Serialization;

/** @brief The Plugin Information struct */
// NOLINTNEXTLINE
struct PluginInfo
{
  /** @brief The plugin class name */
  std::string class_name;

  /** @brief The plugin config data */
  YAML::Node config;

  /** @brief Get the yaml config as a string */
  std::string getConfigString() const;

  bool operator==(const PluginInfo& rhs) const;
  bool operator!=(const PluginInfo& rhs) const;

private:
  friend class boost::serialization::access;
  friend struct tesseract_common::Serialization;
  template <class Archive>
  void save(Archive& ar, const unsigned int version) const;  // NOLINT

  template <class Archive>
  void load(Archive& ar, const unsigned int version);  // NOLINT

  template <class Archive>
  void serialize(Archive& ar, const unsigned int version);  // NOLINT
};

/** @brief A map of PluginInfo to user defined name */
using PluginInfoMap = std::map<std::string, PluginInfo>;

struct PluginInfoContainer
{
  std::string default_plugin;
  PluginInfoMap plugins;
  void clear();

  bool operator==(const PluginInfoContainer& rhs) const;
  bool operator!=(const PluginInfoContainer& rhs) const;

private:
  friend class boost::serialization::access;
  friend struct tesseract_common::Serialization;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version);  // NOLINT
};

/** @brief The profile plugin information structure */
struct ProfilesPluginInfo
{
  /** @brief A list of paths to search for plugins */
  std::set<std::string> search_paths;

  /** @brief A list of library names without the prefix or suffix that contain plugins*/
  std::set<std::string> search_libraries;

  /** @brief A map of name to task composer executor plugin information */
  std::map<std::string, PluginInfoMap> plugin_infos;

  /** @brief Insert the content of an other ProfilesPluginInfo */
  void insert(const ProfilesPluginInfo& other);

  /** @brief Clear the contents */
  void clear();

  /** @brief Check if structure is empty */
  bool empty() const;

  // Yaml Config key
  static inline const std::string CONFIG_KEY{ "profile_plugins" };

  bool operator==(const ProfilesPluginInfo& rhs) const;
  bool operator!=(const ProfilesPluginInfo& rhs) const;

private:
  friend class boost::serialization::access;
  friend struct tesseract_common::Serialization;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version);  // NOLINT
};

/** @brief The kinematics plugin information structure */
struct KinematicsPluginInfo
{
  /** @brief A list of paths to search for plugins */
  std::set<std::string> search_paths;

  /** @brief A list of library names without the prefix or suffix that contain plugins*/
  std::set<std::string> search_libraries;

  /** @brief A map of group name to forward kinematics plugin information */
  std::map<std::string, PluginInfoContainer> fwd_plugin_infos;

  /** @brief A map of group name to inverse kinematics plugin information */
  std::map<std::string, PluginInfoContainer> inv_plugin_infos;

  /** @brief Insert the content of an other KinematicsPluginInfo */
  void insert(const KinematicsPluginInfo& other);

  /** @brief Clear the contents */
  void clear();

  /** @brief Check if structure is empty */
  bool empty() const;

  // Yaml Config key
  static inline const std::string CONFIG_KEY{ "kinematic_plugins" };

  bool operator==(const KinematicsPluginInfo& rhs) const;
  bool operator!=(const KinematicsPluginInfo& rhs) const;

private:
  friend class boost::serialization::access;
  friend struct tesseract_common::Serialization;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version);  // NOLINT
};

/** @brief The contact managers plugin information structure */
struct ContactManagersPluginInfo
{
  /** @brief A list of paths to search for plugins */
  std::set<std::string> search_paths;

  /** @brief A list of library names without the prefix or suffix that contain plugins*/
  std::set<std::string> search_libraries;

  /** @brief A map of name to discrete contact manager plugin information */
  PluginInfoContainer discrete_plugin_infos;

  /** @brief A map of name to continuous contact manager plugin information */
  PluginInfoContainer continuous_plugin_infos;

  /** @brief Insert the content of an other ContactManagersPluginInfo */
  void insert(const ContactManagersPluginInfo& other);

  /** @brief Clear the contents */
  void clear();

  /** @brief Check if structure is empty */
  bool empty() const;

  // Yaml Config key
  static inline const std::string CONFIG_KEY{ "contact_manager_plugins" };

  bool operator==(const ContactManagersPluginInfo& rhs) const;
  bool operator!=(const ContactManagersPluginInfo& rhs) const;

private:
  friend class boost::serialization::access;
  friend struct tesseract_common::Serialization;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version);  // NOLINT
};

/** @brief The task composer plugin information structure */
struct TaskComposerPluginInfo
{
  /** @brief A list of paths to search for plugins */
  std::set<std::string> search_paths;

  /** @brief A list of library names without the prefix or suffix that contain plugins*/
  std::set<std::string> search_libraries;

  /** @brief A map of name to task composer executor plugin information */
  PluginInfoContainer executor_plugin_infos;

  /** @brief A map of name to task composer task plugin information */
  PluginInfoContainer task_plugin_infos;

  /** @brief Insert the content of an other TaskComposerPluginInfo */
  void insert(const TaskComposerPluginInfo& other);

  /** @brief Clear the contents */
  void clear();

  /** @brief Check if structure is empty */
  bool empty() const;

  // Yaml Config key
  static inline const std::string CONFIG_KEY{ "task_composer_plugins" };

  bool operator==(const TaskComposerPluginInfo& rhs) const;
  bool operator!=(const TaskComposerPluginInfo& rhs) const;

private:
  friend class boost::serialization::access;
  friend struct tesseract_common::Serialization;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version);  // NOLINT
};

}  // namespace tesseract_common

BOOST_CLASS_EXPORT_KEY(tesseract_common::PluginInfo)
BOOST_CLASS_EXPORT_KEY(tesseract_common::PluginInfoContainer)
BOOST_CLASS_EXPORT_KEY(tesseract_common::ProfilesPluginInfo)
BOOST_CLASS_EXPORT_KEY(tesseract_common::KinematicsPluginInfo)
BOOST_CLASS_EXPORT_KEY(tesseract_common::ContactManagersPluginInfo)
BOOST_CLASS_EXPORT_KEY(tesseract_common::TaskComposerPluginInfo)

#endif  // TESSERACT_COMMON_PLUGIN_INFO_H
