FROM polyhx/cpp-server

ADD . .

RUN make
CMD ["./ai"]
