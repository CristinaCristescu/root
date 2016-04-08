//--------------------------------------------------------------------*- C++ -*-
// CLING - the C++ LLVM-based InterpreterG :)
// author:  Vassil Vassilev <vasil.georgiev.vasilev@cern.ch>
//
// This file is dual-licensed: you can choose to license it under the University
// of Illinois Open Source License or the GNU Lesser General Public License. See
// LICENSE.TXT for details.
//------------------------------------------------------------------------------

#include "cling/Utils/Validation.h"

#include <assert.h>
#include <errno.h>
#ifdef LLVM_ON_WIN32
# include <Windows.h>
#else
#include <fcntl.h>
# include <unistd.h>
#endif



namespace cling {
  namespace utils {

    static int getNullDevFileDescriptor() {
#ifdef LLVM_ON_WIN32
      return 0;
#else
      struct FileDescriptor {
        int FD;
        const char* file = "/dev/null";
        FileDescriptor() { FD = open(file, O_WRONLY); }
        ~FileDescriptor() {
          close(FD);
        }
      };
      static FileDescriptor nullDev;
      return nullDev.FD;
#endif
    }

    // Checking whether the pointer points to a valid memory location
    // Used for checking of void* output
    // Should be moved to earlier stages (ex. IR) in the future
    bool isAddressValid(const void *P) {
      if (!P || P == (void *) -1)
        return false;

#ifdef LLVM_ON_WIN32
      MEMORY_BASIC_INFORMATION MBI;
      if (!VirtualQuery(P, &MBI, sizeof(MBI)))
        return false;
      if (MBI.State != MEM_COMMIT)
        return false;
      return true;
#else
      // There is a POSIX way of finding whether an address can be accessed for
      // reading: write() will return EFAULT if not.
      int NBytes = write(getNullDevFileDescriptor(), P, 1/*byte*/);
      if (NBytes != 1) {
        assert(errno == EFAULT && "unexpected pipe write error");
        return false;
      }
      return true;
#endif
    }
  }
}
