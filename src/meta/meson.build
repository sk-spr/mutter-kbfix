mutter_public_headers = [
  'barrier.h',
  'boxes.h',
  'common.h',
  'compositor.h',
  'display.h',
  'keybindings.h',
  'main.h',
  'meta-backend.h',
  'meta-base.h',
  'meta-background.h',
  'meta-background-actor.h',
  'meta-background-content.h',
  'meta-background-group.h',
  'meta-background-image.h',
  'meta-backlight.h',
  'meta-close-dialog.h',
  'meta-cursor-tracker.h',
  'meta-context.h',
  'meta-debug.h',
  'meta-debug-control.h',
  'meta-dnd.h',
  'meta-enums.h',
  'meta-idle-monitor.h',
  'meta-inhibit-shortcuts-dialog.h',
  'meta-launch-context.h',
  'meta-later.h',
  'meta-logical-monitor.h',
  'meta-monitor.h',
  'meta-monitor-manager.h',
  'meta-multi-texture.h',
  'meta-multi-texture-format.h',
  'meta-orientation-manager.h',
  'meta-plugin.h',
  'meta-remote-access-controller.h',
  'meta-selection.h',
  'meta-selection-source.h',
  'meta-selection-source-memory.h',
  'meta-settings.h',
  'meta-shaped-texture.h',
  'meta-sound-player.h',
  'meta-stage.h',
  'meta-startup-notification.h',
  'meta-window-actor.h',
  'meta-window-config.h',
  'meta-window-group.h',
  'meta-workspace-manager.h',
  'prefs.h',
  'types.h',
  'util.h',
  'window.h',
  'workspace.h',
]

if have_wayland
  mutter_public_headers += [
    'meta-wayland-client.h',
    'meta-wayland-compositor.h',
    'meta-wayland-surface.h',
  ]
endif

if have_x11_client
  mutter_public_headers += [
    'meta-x11-display.h',
    'meta-x11-types.h',
    'meta-x11-group.h',
  ]
endif

install_headers(mutter_public_headers,
  subdir: mutter_includesubdir
)

mutter_public_header_files = files(mutter_public_headers)

mutter_enum_types = gnome.mkenums('meta-enum-types',
  sources: [mutter_public_headers],
  c_template: 'meta-enum-types.c.in',
  h_template: 'meta-enum-types.h.in',
  install_dir: mutter_includedir,
  install_header: true,
)
