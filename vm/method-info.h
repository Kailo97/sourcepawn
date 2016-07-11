// vim: set sts=2 ts=8 sw=2 tw=99 et:
// 
// Copyright (C) 2006-2015 AlliedModders LLC
// 
// This file is part of SourcePawn. SourcePawn is free software: you can
// redistribute it and/or modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation, either version 3 of
// the License, or (at your option) any later version.
//
// You should have received a copy of the GNU General Public License along with
// SourcePawn. If not, see http://www.gnu.org/licenses/.
//
#ifndef _INCLUDE_SOURCEPAWN_VM_METHOD_INFO_H_
#define _INCLUDE_SOURCEPAWN_VM_METHOD_INFO_H_

#include <sp_vm_types.h>
#include <amtl/am-refcounting.h>
#include <amtl/am-utility.h>

namespace sp {

class PluginRuntime;
class CompiledFunction;

class MethodInfo final : public ke::Refcounted<MethodInfo>
{
 public:
  MethodInfo(PluginRuntime* rt, uint32_t codeOffset);
  ~MethodInfo();

  int Validate() {
    if (!checked_)
      InternalValidate();
    return validation_error_;
  }

  uint32_t pcode_offset() const {
    return pcode_offset_;
  }

  void setCompiledFunction(CompiledFunction* fun);
  CompiledFunction* jit() const {
    return jit_;
  }

 private:
  void InternalValidate();

 private:
  PluginRuntime* rt_;
  uint32_t pcode_offset_;
  ke::AutoPtr<CompiledFunction> jit_;

  bool checked_;
  int validation_error_;
};

} // namespace sp

#endif //_INCLUDE_SOURCEPAWN_VM_METHOD_INFO_H_