#pragma once

#include "torch_xla/csrc/ir.h"

namespace torch_xla {
namespace ir {
namespace ops {

class MaxPoolNdBackward : public Node {
 public:
  MaxPoolNdBackward(const Value& grad_output, const Value& input,
                    xla::int64_t spatial_dim_count,
                    std::vector<xla::int64_t> kernel_size,
                    std::vector<xla::int64_t> stride,
                    std::vector<xla::int64_t> padding, bool ceil_mode);

  NodePtr Clone(OpList operands) const override;

  XlaOpVector Lower(LoweringContext* loctx) const override;

  std::string ToString() const override;

  xla::int64_t spatial_dim_count() const { return spatial_dim_count_; }

  const std::vector<xla::int64_t>& kernel_size() const { return kernel_size_; }

  const std::vector<xla::int64_t>& stride() const { return stride_; }

  const std::vector<xla::int64_t>& padding() const { return padding_; }

  bool ceil_mode() const { return ceil_mode_; }

 private:
  xla::int64_t spatial_dim_count_;
  std::vector<xla::int64_t> kernel_size_;
  std::vector<xla::int64_t> stride_;
  std::vector<xla::int64_t> padding_;
  bool ceil_mode_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_xla
