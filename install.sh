#!/usr/bin/env bash
dir=$(cd -P -- "$(dirname -- "$0")" && pwd -P)

echo $dir

NGINX_DIR=${dir}/ngx_openresty-1.7.2.1
CONTRIB_DIR=${dir}/contrib

cd ${NGINX_DIR}

./configure \
  --with-http_iconv_module \
  --with-http_ssl_module \
  --with-http_spdy_module \
  --with-http_realip_module \
  --with-http_gzip_static_module \
  --with-http_geoip_module \
  --add-module=${CONTRIB_DIR}/nginx-length-hiding-filter-module \

make
sudo make install
