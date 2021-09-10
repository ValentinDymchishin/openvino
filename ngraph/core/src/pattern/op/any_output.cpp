// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "ngraph/pattern/op/any_output.hpp"

#include "ngraph/pattern/matcher.hpp"

using namespace std;

constexpr ov::NodeTypeInfo ov::pass::pattern::op::AnyOutput::type_info;

const ov::NodeTypeInfo& ov::pass::pattern::op::AnyOutput::get_type_info() const {
    return type_info;
}

bool ov::pass::pattern::op::AnyOutput::match_value(Matcher* matcher,
                                                   const Output<Node>& pattern_value,
                                                   const Output<Node>& graph_value) {
    return input_value(0).get_node()->match_node(matcher, graph_value);
}
