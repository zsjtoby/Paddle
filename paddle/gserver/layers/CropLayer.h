/* Copyright (c) 2016 PaddlePaddle Authors. All Rights Reserve.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

#include "Layer.h"

namespace paddle {

/**
 * \brief  This layer crop inputs according to the specify corner and shape.
 *         The input and output is a 4D tensor. Cropping from the 2nd to
 *         the 4th dimenstion.
 */
class CropLayer : public Layer {
public:
  explicit CropLayer(const LayerConfig& config) : Layer(config) {}

  ~CropLayer() {}

  bool init(const LayerMap& layerMap,
            const ParameterMap& parameterMap) override;
  void forward(PassType passType) override;
  void backward(const UpdateCallback& callback = nullptr) override;

protected:
  void setOutDims(const size_t batchSize);
  void setTensorDim(const size_t batchSize);

  std::vector<uint32_t> crop_corner_;
  std::vector<uint32_t> crop_shape_;
  TensorShape inDims_;
  TensorShape outDims_;
};
}  // namespace paddle
