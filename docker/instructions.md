# clang-10 docker image

## Prerequisites for using github docker packages:
* create github credential token: https://github.com/settings/tokens
* login:
```bash
cat ~/Github-token.txt | docker login docker.pkg.github.com -u USERNAME --password-stdin
```

## Build using docker image from github
```bash
docker pull docker.pkg.github.com/reusing-code/exercises/clang10:latest

docker run --rm --name exercises -v $(pwd):/src  docker.pkg.github.com/reusing-code/exercises/clang10:latest \
        /bin/bash -c "cmake /src -G Ninja; ninja; ctest"
```

## Build using docker image built locally
```bash
docker build --tag clang10 docker/

docker run --rm --name exercises -v $(pwd):/src  clang10 \
        /bin/bash -c "cmake /src -G Ninja; ninja; ctest"
```

## Publish new docker image as package

```bash
docker build --tag clang10 docker/

docker tag clang10 docker.pkg.github.com/reusing-code/exercises/clang10:[VERSION]

docker tag clang10 docker.pkg.github.com/reusing-code/exercises/clang10:latest

docker push docker.pkg.github.com/reusing-code/exercises/clang10:[VERSION]

docker push docker.pkg.github.com/reusing-code/exercises/clang10:latest
```