#ifndef DN_VOXEL_SHAPES_H
#define DN_VOXEL_SHAPES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "globals.h"
#include "voxel.h"
#include "QuickMath/quickmath.h"

//--------------------------------------------------------------------------------------------------------------------------------//
//SHAPES:

//NOTE: the shapes are generated using distance fields and thus may not appear exactly as specified when scaled down to the low-resolution voxel map
//for example, a cylinder with a height of 5 might only be 4 voxels tall due to rounding

/* a function used to calculate the placed voxel's color, material, and albedo for the shape functions
 * @param pos the position of the voxel (in DNvoxel's)
 * @param normal the calculated normal of the voxel
 * @param voxel the voxel that was initially passed into the shape function
 * @param shapeMin the minimum point that the shape touches
 * @param shapeMax the maximum point that the shape touches
 * @param invTransform the inverse transform matrix of the shape, use this to go into the shape's "local space"
 * @return the voxel to be placed
 */
typedef DNvoxel (*VoxelTransformFunc)(DNvec3 pos, DNvec3 normal, DNvoxel vox, DNvec3 shapeMin, DNvec3 shapeMax, DNmat4 invTransform, void* userData);

/* Places a sphere into a map
 * @param vol the volume to edit
 * @param voxel the voxel to place (the normal will be calculated automatically)
 * @param flipNormals determines whether or not to update the normals of voxels adjacent to removed voxels, if voxel.material == DN_MATERIAL_EMPTY
 * @param c the sphere's center
 * @param r the sphere's radius
 * @param func the function that is called to determine the voxel that is actually placed or NULL if you just want to place the the voxel from the last param
 * @param userData optional user-defined data that gets passed into the transformation function, if provided
 */
void DN_shape_sphere(DNvolume* vol, DNvoxel voxel, bool flipNormals, DNvec3 c, float r, VoxelTransformFunc func, void* userData);
/* Places a box into a map
 * @param vol the volume to edit
 * @param voxel the voxel to place (the normal will be calculated automatically)
 * @param flipNormals determines whether or not to update the normals of voxels adjacent to removed voxels, if voxel.material == DN_MATERIAL_EMPTY
 * @param c the box's center
 * @param len the distance from the center to the edge of the box, in each direction
 * @param orient the box's orientation, expressed as {pitch, yaw, roll}
 * @param func the function that is called to determine the voxel that is actually placed or NULL if you just want to place the the voxel from the last param
 * @param userData optional user-defined data that gets passed into the transformation function, if provided
 */
void DN_shape_box(DNvolume* vol, DNvoxel voxel, bool flipNormals, DNvec3 c, DNvec3 len, DNquaternion orient, VoxelTransformFunc func, void* userData);
/* Places a rounded box into a map
 * @param vol the volume to edit
 * @param voxel the voxel to place (the normal will be calculated automatically)
 * @param flipNormals determines whether or not to update the normals of voxels adjacent to removed voxels, if voxel.material == DN_MATERIAL_EMPTY
 * @param c the box's center
 * @param len the distance from the center to the edge of the box, in each direction
 * @param r the box's radius
 * @param orient the box's orientation, expressed as {pitch, yaw, roll}
 * @param func the function that is called to determine the voxel that is actually placed or NULL if you just want to place the the voxel from the last param
 * @param userData optional user-defined data that gets passed into the transformation function, if provided
 */
void DN_shape_rounded_box(DNvolume* vol, DNvoxel voxel, bool flipNormals, DNvec3 c, DNvec3 len, float r, DNquaternion orient, VoxelTransformFunc func, void* userData);
/* Places a torus into a map
 * @param vol the volume to edit
 * @param voxel the voxel to place (the normal will be calculated automatically)
 * @param flipNormals determines whether or not to update the normals of voxels adjacent to removed voxels, if voxel.material == DN_MATERIAL_EMPTY
 * @param c the torus's center
 * @param ra the center radius of the torus
 * @param rb the radius of the "ring" of the torus
 * @param orient the torus's orientation, expressed as {pitch, yaw, roll}
 * @param func the function that is called to determine the voxel that is actually placed or NULL if you just want to place the the voxel from the last param
 * @param userData optional user-defined data that gets passed into the transformation function, if provided
 */
void DN_shape_torus(DNvolume* vol, DNvoxel voxel, bool flipNormals, DNvec3 c, float ra, float rb, DNquaternion orient, VoxelTransformFunc func, void* userData);
/* Places an ellipsoid into a map
 * @param vol the volume to edit
 * @param voxel the voxel to place (the normal will be calculated automatically)
 * @param flipNormals determines whether or not to update the normals of voxels adjacent to removed voxels, if voxel.material == DN_MATERIAL_EMPTY
 * @param c the center of the ellipsoid
 * @param r the lengths of the semi-axes of the ellipsoid
 * @param orient the ellipsoid's orientation, expressed as {pitch, yaw, roll}
 * @param func the function that is called to determine the voxel that is actually placed or NULL if you just want to place the the voxel from the last param
 * @param userData optional user-defined data that gets passed into the transformation function, if provided
 */
void DN_shape_ellipsoid(DNvolume* vol, DNvoxel voxel, bool flipNormals, DNvec3 c, DNvec3 r, DNquaternion orient, VoxelTransformFunc func, void* userData);
/* Places a cylinder into a map
 * @param vol the volume to edit
 * @param voxel the voxel to place (the normal will be calculated automatically)
 * @param flipNormals determines whether or not to update the normals of voxels adjacent to removed voxels, if voxel.material == DN_MATERIAL_EMPTY
 * @param c the center of the cylinder
 * @param r the radius of the cylinder
 * @param h the height of the cylinder
 * @param orient the cylinder's orientation, expressed as {pitch, yaw, roll}
 * @param func the function that is called to determine the voxel that is actually placed or NULL if you just want to place the the voxel from the last param
 * @param userData optional user-defined data that gets passed into the transformation function, if provided
 */
void DN_shape_cylinder(DNvolume* vol, DNvoxel voxel, bool flipNormals, DNvec3 c, float r, float h, DNquaternion orient, VoxelTransformFunc func, void* userData);
/* Places a cone into a map
 * @param vol the volume to edit
 * @param voxel the voxel to place (the normal will be calculated automatically)
 * @param flipNormals determines whether or not to update the normals of voxels adjacent to removed voxels, if voxel.material == DN_MATERIAL_EMPTY
 * @param b the position of the cone's base
 * @param r the radius of the cone
 * @param h the height of the cone
 * @param orient the cone's orientation, expressed as {pitch, yaw, roll}
 * @param func the function that is called to determine the voxel that is actually placed or NULL if you just want to place the the voxel from the last param
 * @param userData optional user-defined data that gets passed into the transformation function, if provided
 */
void DN_shape_cone(DNvolume* vol, DNvoxel voxel, bool flipNormals, DNvec3 b, float r, float h, DNquaternion orient, VoxelTransformFunc func, void* userData);

//--------------------------------------------------------------------------------------------------------------------------------//
//VOX FILE MODELS:

//a voxel model
typedef struct DNvoxelModel
{
	DNuvec3 size;
	DNcompressedVoxel* voxels;
} DNvoxelModel;

/* Loads a magicavoxel model from a .vox file
 * @param path the path to the file to load from
 * @param material the material to make the voxels, if negative, the materials will be set to the palette index in magicavoxel
 * @param model populated with the model once loaded
 * @returns true on success, false on failure
 */
bool DN_load_vox_file(const char* path, int material, DNvoxelModel* model);
/* Frees the memory of a model
 * @param model the model to free
*/
void DN_free_model(DNvoxelModel model);

/* Calculates the normals for every voxel in a model as models loaded from magicavoxel have none
 * @param radius the radius, in DNvoxels, to use for the calculation. The larger this value, the smoother the normals but the longer the calculation time
 * @param model the model to calculate the normals for
 */
void DN_calculate_model_normals(int radius, DNvoxelModel* model);

/* Places a model into a map
 * @param vol the volume to place the model into
 * @param model the model to place
 * @param pos the position to place the model at, measured in DNvoxels. This is the minimum coordinate that the model will touch
 */
void DN_place_model_into_volume(DNvolume* vol, DNvoxelModel model, DNivec3 pos);

#ifdef __cplusplus
}
#endif

#endif