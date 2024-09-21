#pragma once

namespace HauntedGraveyard::graphics {
  class Camera2D;
  /**
    * Handles generating primatives / framgments for objects in 2d space 
    */
  class Render2D {
    public:
      /**
        * Sets current active Camera2D
        */
      static void set_camera(HauntedGraveyard::graphics::Camera2D *camera);
    private:
      static HauntedGraveyard::graphics::Camera2D *active_camera;
  };
}
