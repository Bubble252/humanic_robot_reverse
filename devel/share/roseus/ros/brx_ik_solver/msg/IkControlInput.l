;; Auto-generated. Do not edit!


(when (boundp 'brx_ik_solver::IkControlInput)
  (if (not (find-package "BRX_IK_SOLVER"))
    (make-package "BRX_IK_SOLVER"))
  (shadow 'IkControlInput (find-package "BRX_IK_SOLVER")))
(unless (find-package "BRX_IK_SOLVER::IKCONTROLINPUT")
  (make-package "BRX_IK_SOLVER::IKCONTROLINPUT"))

(in-package "ROS")
;;//! \htmlinclude IkControlInput.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass brx_ik_solver::IkControlInput
  :super ros::object
  :slots (_header _pose _solve_type _lock_joint _lock_values ))

(defmethod brx_ik_solver::IkControlInput
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:pose __pose) (instance geometry_msgs::Pose :init))
    ((:solve_type __solve_type) "")
    ((:lock_joint __lock_joint) (let (r) (dotimes (i 0) (push nil r)) r))
    ((:lock_values __lock_values) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _pose __pose)
   (setq _solve_type (string __solve_type))
   (setq _lock_joint __lock_joint)
   (setq _lock_values __lock_values)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:solve_type
   (&optional __solve_type)
   (if __solve_type (setq _solve_type __solve_type)) _solve_type)
  (:lock_joint
   (&optional __lock_joint)
   (if __lock_joint (setq _lock_joint __lock_joint)) _lock_joint)
  (:lock_values
   (&optional __lock_values)
   (if __lock_values (setq _lock_values __lock_values)) _lock_values)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Pose _pose
    (send _pose :serialization-length)
    ;; string _solve_type
    4 (length _solve_type)
    ;; bool[] _lock_joint
    (* 1    (length _lock_joint)) 4
    ;; float64[] _lock_values
    (* 8    (length _lock_values)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Pose _pose
       (send _pose :serialize s)
     ;; string _solve_type
       (write-long (length _solve_type) s) (princ _solve_type s)
     ;; bool[] _lock_joint
     (write-long (length _lock_joint) s)
     (dotimes (i (length _lock_joint))
       (if (elt _lock_joint i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; float64[] _lock_values
     (write-long (length _lock_values) s)
     (dotimes (i (length _lock_values))
       (sys::poke (elt _lock_values i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Pose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;; string _solve_type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _solve_type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool[] _lock_joint
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _lock_joint (make-list n))
     (dotimes (i n)
     (setf (elt _lock_joint i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     ))
   ;; float64[] _lock_values
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _lock_values (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _lock_values i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get brx_ik_solver::IkControlInput :md5sum-) "535926b983805427fbc7baab7e4cdf0a")
(setf (get brx_ik_solver::IkControlInput :datatype-) "brx_ik_solver/IkControlInput")
(setf (get brx_ik_solver::IkControlInput :definition-)
      "Header header
geometry_msgs/Pose pose
string solve_type
bool[] lock_joint
float64[] lock_values


================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :brx_ik_solver/IkControlInput "535926b983805427fbc7baab7e4cdf0a")


