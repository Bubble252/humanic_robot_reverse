; Auto-generated. Do not edit!


(cl:in-package brx_ik_solver-msg)


;//! \htmlinclude IkControlInput.msg.html

(cl:defclass <IkControlInput> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (pose
    :reader pose
    :initarg :pose
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (solve_type
    :reader solve_type
    :initarg :solve_type
    :type cl:string
    :initform "")
   (lock_joint
    :reader lock_joint
    :initarg :lock_joint
    :type (cl:vector cl:boolean)
   :initform (cl:make-array 0 :element-type 'cl:boolean :initial-element cl:nil))
   (lock_values
    :reader lock_values
    :initarg :lock_values
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass IkControlInput (<IkControlInput>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IkControlInput>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IkControlInput)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name brx_ik_solver-msg:<IkControlInput> is deprecated: use brx_ik_solver-msg:IkControlInput instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <IkControlInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brx_ik_solver-msg:header-val is deprecated.  Use brx_ik_solver-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <IkControlInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brx_ik_solver-msg:pose-val is deprecated.  Use brx_ik_solver-msg:pose instead.")
  (pose m))

(cl:ensure-generic-function 'solve_type-val :lambda-list '(m))
(cl:defmethod solve_type-val ((m <IkControlInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brx_ik_solver-msg:solve_type-val is deprecated.  Use brx_ik_solver-msg:solve_type instead.")
  (solve_type m))

(cl:ensure-generic-function 'lock_joint-val :lambda-list '(m))
(cl:defmethod lock_joint-val ((m <IkControlInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brx_ik_solver-msg:lock_joint-val is deprecated.  Use brx_ik_solver-msg:lock_joint instead.")
  (lock_joint m))

(cl:ensure-generic-function 'lock_values-val :lambda-list '(m))
(cl:defmethod lock_values-val ((m <IkControlInput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brx_ik_solver-msg:lock_values-val is deprecated.  Use brx_ik_solver-msg:lock_values instead.")
  (lock_values m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IkControlInput>) ostream)
  "Serializes a message object of type '<IkControlInput>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'solve_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'solve_type))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'lock_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if ele 1 0)) ostream))
   (cl:slot-value msg 'lock_joint))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'lock_values))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'lock_values))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IkControlInput>) istream)
  "Deserializes a message object of type '<IkControlInput>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'solve_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'solve_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'lock_joint) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'lock_joint)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:not (cl:zerop (cl:read-byte istream)))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'lock_values) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'lock_values)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IkControlInput>)))
  "Returns string type for a message object of type '<IkControlInput>"
  "brx_ik_solver/IkControlInput")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IkControlInput)))
  "Returns string type for a message object of type 'IkControlInput"
  "brx_ik_solver/IkControlInput")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IkControlInput>)))
  "Returns md5sum for a message object of type '<IkControlInput>"
  "535926b983805427fbc7baab7e4cdf0a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IkControlInput)))
  "Returns md5sum for a message object of type 'IkControlInput"
  "535926b983805427fbc7baab7e4cdf0a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IkControlInput>)))
  "Returns full string definition for message of type '<IkControlInput>"
  (cl:format cl:nil "Header header~%geometry_msgs/Pose pose~%string solve_type~%bool[] lock_joint~%float64[] lock_values~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IkControlInput)))
  "Returns full string definition for message of type 'IkControlInput"
  (cl:format cl:nil "Header header~%geometry_msgs/Pose pose~%string solve_type~%bool[] lock_joint~%float64[] lock_values~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IkControlInput>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
     4 (cl:length (cl:slot-value msg 'solve_type))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'lock_joint) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'lock_values) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IkControlInput>))
  "Converts a ROS message object to a list"
  (cl:list 'IkControlInput
    (cl:cons ':header (header msg))
    (cl:cons ':pose (pose msg))
    (cl:cons ':solve_type (solve_type msg))
    (cl:cons ':lock_joint (lock_joint msg))
    (cl:cons ':lock_values (lock_values msg))
))
