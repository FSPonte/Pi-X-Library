mkdir -p "logs/"
docker image prune -f # Force remove dangling images

# Check if a container with the name "pixlib" already exists
if [ "$(docker ps -aq -f name=pixlib)" ]; then
    docker container stop pixlib > /dev/null 2>&1
    docker container rm pixlib > /dev/null 2>&1
fi

docker image build -t pixlib "./" 2>&1 | tee logs/docker.txt # Build the image
docker container create --name pixlib pixlib:latest > /dev/null 2>&1 # Create a new container
