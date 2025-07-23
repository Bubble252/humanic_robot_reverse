// Auto-generated. Do not edit!

// (in-package brx_ik_solver.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class IkControlInput {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.pose = null;
      this.solve_type = null;
      this.lock_joint = null;
      this.lock_values = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('pose')) {
        this.pose = initObj.pose
      }
      else {
        this.pose = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('solve_type')) {
        this.solve_type = initObj.solve_type
      }
      else {
        this.solve_type = '';
      }
      if (initObj.hasOwnProperty('lock_joint')) {
        this.lock_joint = initObj.lock_joint
      }
      else {
        this.lock_joint = [];
      }
      if (initObj.hasOwnProperty('lock_values')) {
        this.lock_values = initObj.lock_values
      }
      else {
        this.lock_values = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type IkControlInput
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [pose]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.pose, buffer, bufferOffset);
    // Serialize message field [solve_type]
    bufferOffset = _serializer.string(obj.solve_type, buffer, bufferOffset);
    // Serialize message field [lock_joint]
    bufferOffset = _arraySerializer.bool(obj.lock_joint, buffer, bufferOffset, null);
    // Serialize message field [lock_values]
    bufferOffset = _arraySerializer.float64(obj.lock_values, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type IkControlInput
    let len;
    let data = new IkControlInput(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [pose]
    data.pose = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [solve_type]
    data.solve_type = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [lock_joint]
    data.lock_joint = _arrayDeserializer.bool(buffer, bufferOffset, null)
    // Deserialize message field [lock_values]
    data.lock_values = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += _getByteLength(object.solve_type);
    length += object.lock_joint.length;
    length += 8 * object.lock_values.length;
    return length + 68;
  }

  static datatype() {
    // Returns string type for a message object
    return 'brx_ik_solver/IkControlInput';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '535926b983805427fbc7baab7e4cdf0a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new IkControlInput(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.pose !== undefined) {
      resolved.pose = geometry_msgs.msg.Pose.Resolve(msg.pose)
    }
    else {
      resolved.pose = new geometry_msgs.msg.Pose()
    }

    if (msg.solve_type !== undefined) {
      resolved.solve_type = msg.solve_type;
    }
    else {
      resolved.solve_type = ''
    }

    if (msg.lock_joint !== undefined) {
      resolved.lock_joint = msg.lock_joint;
    }
    else {
      resolved.lock_joint = []
    }

    if (msg.lock_values !== undefined) {
      resolved.lock_values = msg.lock_values;
    }
    else {
      resolved.lock_values = []
    }

    return resolved;
    }
};

module.exports = IkControlInput;
