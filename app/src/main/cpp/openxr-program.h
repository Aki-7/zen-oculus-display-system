#pragma once

#include "common.h"
#include "openxr-context.h"

namespace zen::display_system::oculus {

class OpenXRProgram {
 public:
  DISABLE_MOVE_AND_COPY(OpenXRProgram);
  OpenXRProgram() = default;
  ~OpenXRProgram() = default;

  /* Initialize the OpenXR loader */
  bool InitializeLoader(struct android_app *app) const;

  /* Initialize OpenXRContext */
  bool InitializeContext(
      std::shared_ptr<OpenXRContext> context, struct android_app *app) const;

 private:
  /* Create a new XrInstance and store it in the context */
  bool InitializeInstance(
      std::shared_ptr<OpenXRContext> context, struct android_app *app) const;

  /** Write out
   * - non-layer extensions
   * - available layers' information and their extensions
   **/
  void LogLayersAndExtensions() const;

  /* Convert XrVersion to a human readable version string */
  std::string GetXrVersionString(XrVersion version) const;
};

}  // namespace zen::display_system::oculus
