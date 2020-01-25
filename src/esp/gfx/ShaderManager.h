// Copyright (c) Facebook, Inc. and its affiliates.
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "esp/gfx/Shader.h"

#include <unordered_map>

namespace esp {
namespace gfx {

/**
 * @brief Class which creates, stores, and provides shader lookup
 */
class ShaderManager {
 public:
  /**
   * @brief Gets a @ref Shader by ID
   *
   * @return Pointer to @ref shader, or nullptr if shader does not exist.
   */
  Shader::ptr getShader(const std::string& id);

  /** @overload */
  Shader::cptr getShader(const std::string& id) const;

  /**
   * @brief Creates a @ref Shader
   *
   * @param id    ID of created @ref Shader
   * @param args  Arguments passed to @ref Shader constructor
   * @return Pointer to the created @ref Shader, or nullptr if a shader with the
   * same ID already exists.
   */
  template <typename... ShaderArgs>
  Shader::ptr createShader(std::string id, ShaderArgs&&... args);

  /**
   * @brief Deletes a @ref Shader
   *
   * @return If the @ref Shader existed.
   */
  bool deleteShader(const std::string& id);

 private:
  // shaderID -> Shader
  std::unordered_map<std::string, Shader::ptr> shaders_;
};

}  // namespace gfx
}  // namespace esp
