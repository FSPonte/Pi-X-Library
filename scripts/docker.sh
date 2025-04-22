#!/bin/bash

# Check if a container with the name "pixlib" already exists
if [ "$(docker ps -aq -f name=pixlib)" ]; then
    docker container stop pixlib > /dev/null 2>&1
    docker container rm pixlib > /dev/null 2>&1
fi

# Build the image
docker image build -t pixlib ./

# Create a new container
docker container create --name pixlib pixlib > /dev/null 2>&1

# Check if the container is running
if [ "$(docker ps -q -f name=pixlib)" ]; then
	echo "Container is running"
else
	echo "Container is not running"
fi
