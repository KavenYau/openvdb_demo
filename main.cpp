#include <iostream>

#include "openvdb/openvdb.h"

int main(int argc, char** argv) {
  openvdb::initialize();

  double voxel_size = 0.02;

  openvdb::DoubleGrid::Ptr grid = openvdb::DoubleGrid::create(255);

  // setup scale and tranform
  openvdb::Mat4d m = openvdb::Mat4d::identity();
  m.preScale(openvdb::Vec3d(voxel_size, voxel_size, voxel_size));
  m.preTranslate(openvdb::Vec3d(0, 0, 0));
  m.preRotate(openvdb::math::Z_AXIS, 0);

  // double offset = voxel_size * 0.5;
  // m.postTranslate(openvdb::Vec3d(offset, offset, 0));

  // setup transform and other metadata
  grid->setTransform(openvdb::math::Transform::createLinearTransform(m));
  grid->setGridClass(openvdb::GRID_LEVEL_SET);

  double start = -0.05, sy, step = 0.001;
  int end = fabs(start / step) * 2;

  double x, y;

  x = y = 0.0;
  std::cout << "===========================================" << std::endl;
  std::cout << "x axis:" << std::endl;
  for (int i = 0; i < end; i++) {
    x = start + (step * i);

    openvdb::Vec3d test_mark_grid(grid->worldToIndex(openvdb::Vec3d(x, y, 0.0)));

    openvdb::Vec3d pose_world =
        grid->indexToWorld(openvdb::Coord(test_mark_grid[0], test_mark_grid[1], test_mark_grid[2]));

    std::cout << "points: " << x << " " << y << " " << 0.0 << " pose_world: " << pose_world[0] << " " << pose_world[1]
              << " " << pose_world[2] << std::endl;
  }

  x = y = 0.0;
  std::cout << "===========================================" << std::endl;

  std::cout << "y axis:" << std::endl;
  for (int i = 0; i < end; i++) {
    y = start + (step * i);

    openvdb::Vec3d test_mark_grid(grid->worldToIndex(openvdb::Vec3d(x, y, 0.0)));

    openvdb::Vec3d pose_world =
        grid->indexToWorld(openvdb::Coord(test_mark_grid[0], test_mark_grid[1], test_mark_grid[2]));

    std::cout << "points: " << x << " " << y << " " << 0.0 << " pose_world: " << pose_world[0] << " " << pose_world[1]
              << " " << pose_world[2] << std::endl;
  }

  return 0;
}