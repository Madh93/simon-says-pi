# golang image where workspace (GOPATH) configured at /go.
FROM golang:1.8

# Install dependencies
RUN go get gopkg.in/mgo.v2
RUN go get github.com/gorilla/mux
RUN go get github.com/ant0ine/go-json-rest/rest
RUN go get gopkg.in/mgo.v2/bson

# copy the local package files to the container workspace
ADD . /go/src/gowebservice

# Setting up working directory
WORKDIR /go/src/gowebservice

# Build the users command inside the container.
RUN go install gowebservice

# Run the users microservice when the container starts.
ENTRYPOINT /go/bin/gowebservice

# Service listens on port 8080.
EXPOSE 8080
