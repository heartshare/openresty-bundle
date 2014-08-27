#!/usr/bin/env bash
dir=$(cd -P -- "$(dirname -- "$0")" && pwd -P)

apt-get install -y libreadline-dev libncurses5-dev libpcre3-dev libssl-dev perl make checkinstall

NGINX_DIR=${dir}/ngx_openresty
CONTRIB_DIR=${dir}/contrib

cd "${NGINX_DIR}"
make

cd "${NGINX_DIR}/ngx_openresty-1.7.2.1"

auto-apt run ./configure \
  --prefix=/usr/local \
  --with-pcre-jit \
  --with-ipv6 \
  --with-http_ssl_module \
  --with-http_spdy_module \
  --with-http_realip_module \
  --with-http_gzip_static_module \
  #--add-module="${CONTRIB_DIR}/form-input-nginx-module" \
  --add-module="${CONTRIB_DIR}/nginx-length-hiding-filter-module" \
  -j2

make
cp ${dir}/description-pak ${NGINX_DIR}/ngx_openresty-1.7.2.1
sudo checkinstall \
  --pkgname='inviqa-nginx' \
  --pkglicense='MIT' \
  --pkgversion='0.1' \
  --pkgrelease='ubuntu' \
  --pkgsource='https://github.com/shrikeh/openresty-bundle' \
  --pakdir='/var/output' \
  --maintainer='barney@shrikeh.net' \
  --type=debian \
  --install=no \
  --default \
  --showinstall=no \
  --nodoc
