FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    && rm -rf /var/lib/apt/lists/*

COPY . /usr/src/app

WORKDIR /usr/src/app

RUN cmake .

RUN make

CMD ["./neutrino"]
