FROM ubuntu:latest
RUN apt-get update
RUN apt-get install -y --no-install-recommends apt-utils build-essential sudo git cppcheck cmake python3-pip wget googletest
RUN pip3 install cpplint
RUN cd /usr/src/googletest && mkdir -p build && cd build && cmake CMAKE_INSTALL_PREFIX:PATH=/usr .. && make && make install

RUN useradd -m docker && echo "docker:docker" | chpasswd && adduser docker sudo
USER docker
WORKDIR /home/docker


COPY . .
