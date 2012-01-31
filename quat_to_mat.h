#ifndef IGL_QUAT_TO_MAT_H
#define IGL_QUAT_TO_MAT_H
// Name history:
//   quat2mat  until 16 Sept 2011
namespace igl
{
  // Convert a quaternion to a 4x4 matrix
  // A Quaternion, q, is defined here as an arrays of four scalars (x,y,z,w),
  // such that q = x*i + y*j + z*k + w
  // Input:
  //   quat  pointer to four elements of quaternion (x,y,z,w)  
  // Output:
  //   mat  pointer to 16 elements of matrix
  template <typename Q_type>
  inline void quat_to_mat(const Q_type * quat, Q_type * mat);
}

// Implementation

template <typename Q_type>
inline void igl::quat_to_mat(const Q_type * quat, Q_type * mat)
{
  Q_type yy2 = 2.0f * quat[1] * quat[1];
  Q_type xy2 = 2.0f * quat[0] * quat[1];
  Q_type xz2 = 2.0f * quat[0] * quat[2];
  Q_type yz2 = 2.0f * quat[1] * quat[2];
  Q_type zz2 = 2.0f * quat[2] * quat[2];
  Q_type wz2 = 2.0f * quat[3] * quat[2];
  Q_type wy2 = 2.0f * quat[3] * quat[1];
  Q_type wx2 = 2.0f * quat[3] * quat[0];
  Q_type xx2 = 2.0f * quat[0] * quat[0];
  mat[0*4+0] = - yy2 - zz2 + 1.0f;
  mat[0*4+1] = xy2 + wz2;
  mat[0*4+2] = xz2 - wy2;
  mat[0*4+3] = 0;
  mat[1*4+0] = xy2 - wz2;
  mat[1*4+1] = - xx2 - zz2 + 1.0f;
  mat[1*4+2] = yz2 + wx2;
  mat[1*4+3] = 0;
  mat[2*4+0] = xz2 + wy2;
  mat[2*4+1] = yz2 - wx2;
  mat[2*4+2] = - xx2 - yy2 + 1.0f;
  mat[2*4+3] = 0;
  mat[3*4+0] = mat[3*4+1] = mat[3*4+2] = 0;
  mat[3*4+3] = 1;
}
#endif
