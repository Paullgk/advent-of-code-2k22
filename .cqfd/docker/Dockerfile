#
FROM debian:bookworm
USER root
RUN apt-get update && apt-get install -y --no-install-recommends \
	git-core \
	ca-certificates \
	jq \
	curl \
	ninja-build \
	build-essential \
	cmake \
	extra-cmake-modules

RUN git clone https://github.com/google/googletest.git && \
	cd googletest && \
	git checkout v1.17.0
