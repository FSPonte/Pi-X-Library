# Use an official GCC image as a parent image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /app

# Install required dependencies
RUN \
	apt update && apt upgrade -y && apt install -y \
    cmake \
    bsdmainutils \
    binutils \
    tree \
	time \
	gnuplot \
    && rm -rf /var/lib/apt/lists/*

# Copy the current directory contents into the container at /app
COPY ./ /app

# Make the build and run scripts executable
RUN chmod +x scripts/build.sh scripts/run.sh

# Run the bash script to build the application and debug the output
RUN scripts/build.sh && ls -l build

# Run the application using the run script
CMD ["scripts/run.sh"]