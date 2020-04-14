# Publish new docker image as package

## Requirements:
* Docker
* github credential token


## Steps
```bash
cat ~/Github-token.txt | docker login docker.pkg.github.com -u USERNAME --password-stdin

docker build --tag clang10 docker/

docker tag clang10 docker.pkg.github.com/reusing-code/exercises/clang10:[VERSION]

docker tag clang10 docker.pkg.github.com/reusing-code/exercises/clang10:latest

docker push docker.pkg.github.com/reusing-code/exercises/clang10:[VERSION]

docker push docker.pkg.github.com/reusing-code/exercises/clang10:latest
```