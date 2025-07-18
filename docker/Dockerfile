ARG TAG
FROM ubuntu:${TAG}
ARG TAG # Redeclare to use in this stage

SHELL ["/bin/bash", "-c"]

ENV DEBIAN_FRONTEND noninteractive

USER root

# Install
RUN apt update \
  && apt upgrade -y \
  && apt install -y cmake curl git python3 liboctomap-dev

# Add ROS2 sources to install ROS infrastructure tools
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg \
  && echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Install and configure ROS infrastructure tools
RUN apt update -y -qq \
  && apt install -y -qq python3-vcstool python3-colcon-common-extensions python3-rosdep \
  && rosdep init \
  && rosdep update

# Install the dependency repositories
# Use a tmpfs mount for the workspace so as not to unnecessarily copy files into the final image
# Bind mount the source directory so as not to unnecessarily copy source code into the docker image
ARG WORKSPACE_DIR=/tmpfs/tesseract
ARG INSTALL_DIR=/opt/tesseract
RUN mkdir -p ${INSTALL_DIR}

RUN --mount=type=tmpfs,target=${WORKSPACE_DIR} --mount=type=bind,target=${WORKSPACE_DIR}/src/tesseract \
  cd ${WORKSPACE_DIR} \
  && if [ "$TAG" = "focal" ]; then \
       vcs import src < src/tesseract/dependencies_focal.repos --shallow; \
     else \
       vcs import src < src/tesseract/dependencies.repos --shallow; \
     fi \
  && rosdep install \
    --from-paths ${WORKSPACE_DIR}/src \
    -iry \
  && colcon build --cmake-args -DCMAKE_BUILD_TYPE=Release \
  && cp -r ${WORKSPACE_DIR}/install ${INSTALL_DIR}
