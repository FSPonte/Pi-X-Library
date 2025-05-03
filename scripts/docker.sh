#!/bin/bash

mkdir -p "logs/"

# Check if a container with the name "pixlib" already exists
if [ "$(docker ps -aq -f name=pixlib)" ]; then
    docker container stop pixlib > /dev/null 2>&1
    docker container rm pixlib > /dev/null 2>&1
fi

# Build the image
docker image build -t pixlib "./" 2>&1 | tee logs/docker.txt

# Create a new container
docker container create --name pixlib pixlib:latest > /dev/null 2>&1
