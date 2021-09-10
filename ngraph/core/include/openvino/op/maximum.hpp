// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/op/util/binary_elementwise_arithmetic.hpp"

namespace ov {
namespace op {
namespace v1 {
/// \brief Elementwise maximum operation.
class OPENVINO_API Maximum : public util::BinaryElementwiseArithmetic {
public:
    OPENVINO_RTTI_DECLARATION;

    /// \brief Constructs a maximum operation.
    Maximum() : util::BinaryElementwiseArithmetic(AutoBroadcastSpec::NUMPY) {}

    /// \brief Constructs a maximum operation.
    ///
    /// \param arg0 Node that produces the first input tensor.
    /// \param arg1 Node that produces the second input tensor.
    /// \param auto_broadcast Auto broadcast specification
    Maximum(const Output<Node>& arg0,
            const Output<Node>& arg1,
            const AutoBroadcastSpec& auto_broadcast = AutoBroadcastSpec(AutoBroadcastType::NUMPY));

    std::shared_ptr<Node> clone_with_new_inputs(const OutputVector& new_args) const override;

    bool evaluate(const HostTensorVector& outputs, const HostTensorVector& inputs) const override;
    bool has_evaluate() const override;
};
}  // namespace v1
}  // namespace op
}  // namespace ov
