#!/usr/bin/env bash
dir=$(cd -P -- "$(dirname -- "$0")" && pwd -P)

echo $dir

apt-get install libreadline-dev libncurses5-dev libpcre3-dev libssl-dev perl make

NGINX_DIR=${dir}/ngx_openresty-1.7.2.1
CONTRIB_DIR=${dir}/contrib

cd ${NGINX_DIR}

./configure \
  --prefix=/url/local \
  --with-pcre-jit \
  --with-ipv6 \
  --with-http_ssl_module \
  --with-http_spdy_module \
  --with-http_realip_module \
  --with-http_gzip_static_module \
  --add-module="${CONTRIB_DIR}/nginx-length-hiding-filter-module" \
  -j2

make
sudo make install
