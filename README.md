# Tesseract

[![codecov](https://codecov.io/gh/tesseract-robotics/tesseract/branch/master/graph/badge.svg?token=nh4aHZzgpR)](https://codecov.io/gh/tesseract-robotics/tesseract)

[![Python](https://img.shields.io/badge/python-3.7+-blue.svg)](https://github.com/tesseract-robotics/tesseract_python)

![PyPI](https://img.shields.io/pypi/v/tesseract-robotics)

Platform             | CI Status
---------------------|:---------
Linux (Focal)        | [![Build Status](https://github.com/tesseract-robotics/tesseract/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/tesseract-robotics/tesseract/actions/workflows/ubuntu.yml)
Windows              | [![Build Status](https://github.com/tesseract-robotics/tesseract/actions/workflows/windows.yml/badge.svg)](https://github.com/tesseract-robotics/tesseract/actions/workflows/windows.yml)
Lint  (Clang-Format) | [![Build Status](https://github.com/tesseract-robotics/tesseract/actions/workflows/clang_format.yml/badge.svg)](https://github.com/tesseract-robotics/tesseract/actions/workflows/clang_format.yml)
Lint  (CMake-Format) | [![Build Status](https://github.com/tesseract-robotics/tesseract/actions/workflows/cmake_format.yml/badge.svg)](https://github.com/tesseract-robotics/tesseract/actions/workflows/cmake_format.yml)
Lint  (Clang-Tidy)   | [![Build Status](https://github.com/tesseract-robotics/tesseract/actions/workflows/code_quality.yml/badge.svg)](https://github.com/tesseract-robotics/tesseract/actions/workflows/code_quality.yml)
Lint  (CodeCov)      | [![Build Status](https://github.com/tesseract-robotics/tesseract/actions/workflows/code_quality.yml/badge.svg)](https://github.com/tesseract-robotics/tesseract/actions/workflows/code_quality.yml)

[![Github Issues](https://img.shields.io/github/issues/tesseract-robotics/tesseract.svg)](http://github.com/tesseract-robotics/tesseract/issues)

[![license - apache 2.0](https://img.shields.io/:license-Apache%202.0-yellowgreen.svg)](https://opensource.org/licenses/Apache-2.0)
[![license - bsd 2 clause](https://img.shields.io/:license-BSD%202--Clause-blue.svg)](https://opensource.org/licenses/BSD-2-Clause)

[![support level: consortium](https://img.shields.io/badge/support%20level-consortium-brightgreen.png)](http://rosindustrial.org/news/2016/10/7/better-supporting-a-growing-ros-industrial-software-platform)

The planning framework (Tesseract) was designed to be light weight, limiting the number of dependencies, mainly only using standard libraries like, eigen, boost, orocos and to the packages below. The core packages are ROS agnostic and have full python support.

## Dependencies
[![ros_industrial_cmake_boilerplate](https://img.shields.io/badge/ros_industrial_cmake_boilerplate-0.7.3-brightgreen)](https://github.com/ros-industrial/ros_industrial_cmake_boilerplate/tree/0.7.3)  
[![opw_kinematics](https://img.shields.io/badge/opw_kinematics-0.5.2-brightgreen)](https://github.com/Jmeyer1292/opw_kinematics/tree/0.5.2)

## Tesseract Setup Wizard and Visualization Tools

[![](https://github.com/snapcore/snap-store-badges/blob/master/EN/%5BEN%5D-snap-store-black-uneditable%401x.png)](https://snapcraft.io/tesseract-ignition)

## Python Installation

A self contained Tesseract Python package is available on PyPI for Windows 10+, Ubuntu 20.04, and Ubuntu 22.04. This package
contains Tesseract, Tesseract Planning, and all dependencies in the single package. Packages are available for Python
3.7 - 3.10.

To install on Windows:
```
python -m pip install tesseract-robotics tesseract-robotics-viewer
```
To install on Ubuntu 20.04 and Ubuntu 22.04:

```
sudo apt install python3-pip python3-numpy
# The supplied version of pip on Ubuntu 20.04 is too old for manylinux_2_31, upgrade pip
python3 -m pip install -U pip
python3 -m pip install --user  tesseract_robotics tesseract_robotics_viewer
```

## Tesseract Core Packages

* **tesseract** – This is the main class that manages the major component Environment, Forward Kinematics, Inverse Kinematics and loading from various data.
* **tesseract_command_language** – This package contains a generic command language to support motion and process planning similar to industrial teach pendants
* **tesseract_collision** – This package contains a common interface for collision checking prividing several implementation of a Bullet collision library and FCL collision library. It includes both continuous and discrete collision checking for convex-convex, convex-concave and concave-concave shapes.
* **tesseract_common** – This package contains common functionality needed by the majority of the packages.
* **tesseract_environment** – This package contains the Tesseract Environment which provides functionality to add,remove,move and modify links and joint. It also manages adding object to the contact managers and provides the ability.
* **tesseract_geometry** – This package contains geometry types used by Tesseract including primitive shapes, mesh, convex hull mesh, octomap and signed distance field.
* **tesseract_kinematics** –  This package contains a common interface for Forward and Inverse kinematics for Chains, Trees and Graphs including implementation using KDL and OPW Kinematics.
* **tesseract_scene_graph** – This package contains the scene graph which is the data structure used to manage the connectivity of objects in the environment. It inherits from boost graph and provides addition functionality for adding,removing and modifying Links and Joints along with search implementation.
* **tesseract_support** – This package contains support data used for unit tests and examples throughout Tesseract.
* **tesseract_visualization** – This package contains visualization utilities and libraries.

## Related Repositories

* [Tesseract Planning](https://github.com/tesseract-robotics/tesseract_planning)
* [Tesseract Python](https://github.com/tesseract-robotics/tesseract_python)
* [Tesseract ROS](https://github.com/tesseract-robotics/tesseract_ros)
* [Tesseract Documentation](https://github.com/tesseract-robotics/tesseract_docs)

## Documentation

* [Wiki](https://tesseract-docs.readthedocs.io)
* [Doxygen](https://tesseract-robotics.github.io/tesseract/)
* [Benchmark](https://tesseract-robotics.github.io/tesseract_docs/tesseract/dev/bench/)

## Evolution

[![Tesseract Evolution Video](gh_pages/_static/tesseract_evolution.png)](https://www.youtube.com/watch?v=rxlzlsSBxAY)

How to create:

* Create Video: `gource -1280x720 -seconds-per-day 0.2 --auto-skip-seconds 0.2 --disable-bloom -background d0d3d4 --hide filenames,mouse,progress -o - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i - -vcodec libx264 -preset ultrafast -pix_fmt yuv420p -crf 1 -threads 0 -bf 0 gource.mp4`
* Create Gif: `ffmpeg -i gource.mp4 -r 10 -vf "scale=800:-1,split[s0][s1];[s0]palettegen[p];[s1][p]paletteuse" tesseract_evolution.gif`

## Docker Development Container

It common to leverage docker to develop for different distributions of Ubuntu, so a docker compose file has been provided to simplify this process for Tesseract development.

Initial setup, you must create directories for the different distributions to save Qt Creator configs so they persist.

``` bash
mkdir ~/.config/QtProjectDocker
mkdir ~/.config/QtProjectDocker/focal
mkdir ~/.config/QtProjectDocker/noetic
mkdir ~/.config/QtProjectDocker/jammy
```

Now you can start the development docker. Replace focal with what ubuntu distro you want to develope with.

``` bash
cd <path to tesseract repo>/docker
USER_ID=$(id -u) GROUP_ID=$(id -g) UBUNTU_TAG=focal docker compose -f docker-compose-dev.yaml up --build --remove-orphans
```

## TODO's

Warning: These packages are under heavy development and are subject to change.

See [issue #66](https://github.com/tesseract-robotics/tesseract/issues/66)

## Build Instructions

1) Clone repository into your workspace
2) Clone the repositories in the dependencies.repos file using wstool or some other method (e.g. manually git cloning them)
3) Build the workspace using catkin tools, colcon, or a similar tool

NOTE: For noetic tesseract_ext is not required. Install the following dependencies: libbullet-dev, libbullet-extras-dev and ros-noetic-fcl. Taskflow can be install using the PPA below.

NOTE: To speed up clean build you may want to add tesseract_ext to an extended workspace.

NOTE: Install TaskFlow from [ROS-Industrial PPA](https://launchpad.net/~ros-industrial/+archive/ubuntu/ppa).

### Building with Clang-Tidy Enabled

Must pass the -DTESSERACT_ENABLE_CLANG_TIDY=ON to cmake when building. This is automatically enabled if cmake argument -DTESSERACT_ENABLE_TESTING_ALL=ON is passed.

Clang-Tidy Versions Tested:
- clang-tidy-12
- clang-tidy-17 with libomp-17-dev

### Building Tesseract Tests

Must pass the -DTESSERACT_ENABLE_TESTING=ON to cmake when wanting to build tests. This is automatically enabled if cmake argument -DTESSERACT_ENABLE_TESTING_ALL=ON is passed.

NOTE: If you are building using catkin tools, use `catkin build --force-cmake -DTESSERACT_ENABLE_TESTING=ON`.

#### Running Tesseract Tests

Tesseract packages use ctest because it is ROS agnostic, so to run the test call `catkin test --no-deps tesseract_collision tesseract_common tesseract_environment tesseract_geometry tesseract_kinematics tesseract_scene_graph tesseract_urdf tesseract_command_language`

### Building Tesseract Code Coverage

Must pass the -DTESSERACT_ENABLE_CODE_COVERAGE=ON to cmake when wanting to build code coverage. The code coverage report is located in each individuals build directory inside a ccov/all-merged folder. Open the index.html file to see the packages code coverage report.

NOTE: Must be a clean build when generating a code coverage report. Also must build in debug.

#### Exclude Code From Code Coverage

- LCOV_EXCL_LINE
  - Lines containing this marker will be excluded.
- LCOV_EXCL_START
  - Marks the beginning of an excluded section. The current line is part of this section.
- LCOV_EXCL_STOP
  - Marks the end of an excluded section. The current line not part of this section.

.. NOTE: You can replace **LCOV** above with **GCOV** or **GCOVR**.

## Boost Serialization

This package leverages boost serialization. When adding new classes which may be inherited from and then serialized as the base type it is imported to add the following macros for the base type and all derived types.

- Header
  - Abstract Class
    - `BOOST_SERIALIZATION_ASSUME_ABSTRACT(tesseract_common::JointLimits)`
  - Non-Abstract Class
    - `BOOST_CLASS_EXPORT_KEY(tesseract_common::JointLimits)`
- Cpp
  - `BOOST_CLASS_EXPORT_IMPLEMENT(tesseract_common::JointLimits)`

## Create Debian Package (Linux) or NuGet Package (Windows)

The following process will generate a Debian or NuGet package leveraging cmake and cpack based on the OS.

The package should be located in the current directory.

``` bash
cd <workspace directory>
catkin build -DCMAKE_BUILD_TYPE=Release -DTESSERACT_PACKAGE=ON
./src/tesseract/.run-cpack
```

.. NOTE: You can add a prefix to the package name by setting -DTESSERACT_PACKAGE_PREFIX="ros-noetic-".

## Quality Tools Leverage

Tesseract currently leverages Compiler Warnigs, Clang Tidy and Code Coverage. All warnings produced by Compiler and Clang Tidy are treated as errors during CI builds.

- Compiler
  - Wall
  - Wextra
  - Wconversion
  - Wsign-conversion
  - Wno-sign-compare
  - Wnon-virtual-dtor
- Clang Tidy
  - see internal .clang-tidy file for enabled checks

## Documentation and Tutorials
Documentation and tutorials for Tesseract are located at https://github.com/tesseract-robotics/tesseract_docs.git

## Debugging Windows Build

- Search Directories CI
  - dir /s /b c:\opt\ros\noetic\*assimp*
- Location of ROS Windows Builds
  - https://ros-win.visualstudio.com/ros-win/_build
  - https://ros-win.visualstudio.com/ros-win/_build/results?buildId=8711&view=artifacts&type=publishedArtifacts
