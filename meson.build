project('com.github.arnevg.buba', 'vala', 'c')

executable(
    meson.project_name(),
    'Main.vala',
    'Window.vala',
    'Application.vala',
    'Command.vala',
    dependencies: [
        dependency('gtk+-3.0'),
        meson.get_compiler('vala').find_library('posix')
    ],
    install : true
)