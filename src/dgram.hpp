/* SPDX-License-Identifier: MPL-2.0 */

#ifndef __ZMQ_DGRAM_HPP_INCLUDED__
#define __ZMQ_DGRAM_HPP_INCLUDED__

#include "blob.hpp"
#include "socket_base.hpp"
#include "session_base.hpp"

namespace zmq
{
class ctx_t;
class msg_t;
class pipe_t;
class io_thread_t;

class dgram_t ZMQ_FINAL : public socket_base_t
{
  public:
    dgram_t (zmq::ctx_t *parent_, uint32_t tid_, int sid_);
    ~dgram_t ();

    //  Overrides of functions from socket_base_t.
    void xattach_pipe (zmq::pipe_t *pipe_,
                       bool subscribe_to_all_,
                       bool locally_initiated_);
    int xsend (zmq::msg_t *msg_);
    int xrecv (zmq::msg_t *msg_);
    bool xhas_in ();
    bool xhas_out ();
    void xread_activated (zmq::pipe_t *pipe_);
    void xwrite_activated (zmq::pipe_t *pipe_);
    void xpipe_terminated (zmq::pipe_t *pipe_);

  private:
    zmq::pipe_t *_pipe;

    //  If true, more outgoing message parts are expected.
    bool _more_out;

    ZMQ_NON_COPYABLE_NOR_MOVABLE (dgram_t)
};
}

#endif
