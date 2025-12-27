# task manager

a simple terminal task manager for linux, kinda like htop but simpler

## what it does

- shows running processes with CPU and memory usage
- real-time updates
- multiple color themes (press 't' to cycle through them)
- search/filter processes
- kill processes
- vim-style navigation (j/k)
- mouse scrolling support

## building

you need ncurses installed:

```bash
# debian/ubuntu
sudo apt-get install libncurses5-dev

# arch
sudo pacman -S ncurses

# fedora/rhel
sudo yum install ncurses-devel
```

then just:

```bash
make
./task_manager
```

## controls

| key | what it does |
|-----|--------------|
| q | quit |
| j/k or arrows | move up/down |
| gg | jump to top (vim style) |
| G | jump to bottom |
| m | sort by memory |
| c | sort by CPU |
| p | sort by PID |
| t | change theme |
| / | search/filter |
| ESC | clear filter |
| Enter | show/hide process details |
| 1 | toggle per-core CPU view |
| K | kill selected process (sends SIGTERM) |

## notes

- you might need sudo to kill processes owned by other users
- works on linux only (uses /proc filesystem)
- tested on ubuntu and arch

## themes

there's like 10 different color themes (all of them sucks though) :
- default (cyan)
- dracula
- matrix (green, my fav)
- solarized
- monokai
- gruvbox
- nord
- catppuccin
- tokyo night
- everforest

## todo

- [ ] maybe add network stats?
- [ ] tree view for parent/child processes
- [ ] config file support

## license

MIT or whatever, do what you want with it
