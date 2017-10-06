FROM polyhx/cpp-server

ADD . .

EXPOSE 5046

RUN make
CMD ["./ai"]
