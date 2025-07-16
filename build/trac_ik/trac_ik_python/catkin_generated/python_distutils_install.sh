#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/root/arm/reverse_ws/src/trac_ik/trac_ik_python"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/root/arm/reverse_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/root/arm/reverse_ws/install/lib/python3/dist-packages:/root/arm/reverse_ws/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/root/arm/reverse_ws/build" \
    "/usr/bin/python3" \
    "/root/arm/reverse_ws/src/trac_ik/trac_ik_python/setup.py" \
     \
    build --build-base "/root/arm/reverse_ws/build/trac_ik/trac_ik_python" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/root/arm/reverse_ws/install" --install-scripts="/root/arm/reverse_ws/install/bin"
