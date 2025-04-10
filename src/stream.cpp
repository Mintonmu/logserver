#include "stream.h"

Stream::Stream() : fd_(-1) {}

Stream::~Stream() {
  if (fd_ != -1) {
    ::close(fd_);
  }
}

void Stream::Attach(int fd) { fd_ = fd; }

bool Stream::CanRead(int timeout) {
  struct pollfd pf;
  pf.fd = fd_;
  pf.events = POLLIN;
  pf.revents = 0;

  int n = ::poll(&pf, 1, timeout);
  if (n > 0) {
    if (pf.revents & POLLIN) {
      return true;
    }
  }
  return false;
}

// void Stream::Send(const ::google::protobuf::Message &cmd) {}

// bool Stream::Recv(::google::protobuf::Message &cmd) {}

int Stream::fd() { return fd_; }

void Stream::WriteAll(const char *buf, int n) {}

// bool Stream::ReadFull(char *buf, int i) {}
