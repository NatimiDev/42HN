FROM debian:bullseye

# Install necessary tools
RUN apt-get update && apt-get install -y libbsd-dev \
    gcc \
    make \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Set working directory inside the container
WORKDIR /libft

# Copy your project files into the container
COPY ./libft/ .

