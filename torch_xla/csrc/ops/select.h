#pragma once

#include "torch_xla/csrc/ir.h"

namespace torch_xla {
namespace ir {
namespace ops {

class Select : public Node {
 public:
  Select(const Value& input, xla::int64_t dim, xla::int64_t start,
         xla::int64_t end, xla::int64_t stride);

  NodePtr Clone(OpList operands) const override;

  XlaOpVector Lower(LoweringContext* loctx) const override;

  std::string ToString() const override;

  xla::int64_t dim() const { return dim_; }

  xla::int64_t start() const { return start_; }

  xla::int64_t end() const { return end_; }

  xla::int64_t stride() const { return stride_; }

  static xla::Shape MakeSelectShape(const xla::Shape& shape, xla::int64_t dim,
                                    xla::int64_t start, xla::int64_t end,
                                    xla::int64_t stride);

  static xla::int64_t GetStride(xla::int64_t start, xla::int64_t end,
                                xla::int64_t stride);

 private:
  xla::int64_t dim_;
  xla::int64_t start_;
  xla::int64_t end_;
  xla::int64_t stride_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_xla
