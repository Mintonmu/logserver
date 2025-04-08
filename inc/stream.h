#ifndef __STREAM_H__
#define __STREAM_H__

#include <poll.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <unistd.h>

class Stream {
public:
  static const int MIN_MESSAGE_BUFFER_SIZE = 1 << 16; // 64k
  static const int MAX_MESSAGE_BUFFER_SIZE = 1 << 27; // 128m

  Stream();

  ~Stream();

  void Attach(int fd);

  void MarkChild();

  bool CanRead(int timeout);

  void Send(const ::google::protobuf::Message &cmd);

  bool Recv(::google::protobuf::Message &cmd);

  int fd();

private:
  int fd_;
  bool childStream_;
  char buf_[MIN_MESSAGE_BUFFER_SIZE];
  char wbuf_[MIN_MESSAGE_BUFFER_SIZE];

  void WriteAll(const char *buf, int n);

  bool ReadFull(char *buf, int i);
};
#endif // __STREAM_H__