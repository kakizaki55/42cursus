

# is bullseye the best here?
FROM debian:bullseye

#installing nginx and open ssl
RUN apt-get update && apt-get install -y nginx  openssl

RUN mkdir /etc/nginx/ssl

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
       -out /etc/nginx/ssl/mkakizak.crt \
       -keyout /etc/nginx/ssl/mkakizak.key \
       -subj "/C=JP/ST=Tokyo/L=Tokyo/O=school 42/OU=mkakizak/CN=mkakizak/"

# copying config file to /etc/...
COPY ./conf/nginx.conf /etc/nginx/conf.d

# nginx config
RUN mkdir -p /run/nginx

#the only port allowed
EXPOSE	443

# Start nginx
CMD ["nginx", "-g", "daemon off;"]