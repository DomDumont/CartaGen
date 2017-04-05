# If there is no version tag in git this one will be used
VERSION = 0.1.0

# Need to discard STDERR so get path to NULL device
win32 {
    NULL_DEVICE = NUL # Windows doesn't have /dev/null but has NUL
} else {
    NULL_DEVICE = /dev/null
}

# Need to call git with manually specified paths to repository
BASE_GIT_COMMAND = git

# Trying to get version from git tag / revision
GIT_VERSION = $$system($$BASE_GIT_COMMAND describe )

message("coucou")
message($$GIT_VERSION)

DEFINES += GIT_VERSION=\\\"$$GIT_VERSION\\\"

