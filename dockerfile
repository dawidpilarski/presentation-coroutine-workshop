FROM ubuntu:19.04
LABEL maintainer="dawid.pilarski@panicsoftware.com"
RUN apt-get update
RUN apt-get install -y --no-install-recommends software-properties-common
RUN apt-get install -y --no-install-recommends wget git vim
RUN apt-get update
RUN apt-get install -y --no-install-recommends cmake make
RUN apt-get install -y --no-install-recommends gcc g++ g++-6 g++-7 g++-8
RUN apt-get install -y --no-install-recommends clang clang-6.0 clang-7 clang-8
RUN apt-get install -y --no-install-recommends libc++1-8 libc++-8-dev libc++abi-dev
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/*
RUN git clone https://github.com/dawidpilarski/programistamag-coroutines.git
WORKDIR /programistamag-coroutines/