***memleap_hook.c***

```c
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ mkdir mem
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ ls
mem  memleap_hook  memleap_hook.c  memleap_macro.c  memleap_mtrace.c  readme.md
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ gcc -o memleap_hook memleap_hook.c  -ldl -g
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ ./memleap_hook
[+0x15cc]--->ptr:0x558c74d602a0 size:10
[+0x15da]--->ptr:0x558c74d606d0 size:20
[-0x15ea]--->ptr:0x558c74d602a0
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ cd mem
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件/mem$ ls
0x558c74d606d0.mem
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件/mem$ cat 0x558c74d606d0.mem
0x00000000000015da
main
/home/luffy/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件/memleap_hook.c:83
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件/mem$
90.mem
```



***memleap_macro.c***



```c
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ mkdir mem
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ ls
mem  memleap_hook  memleap_hook.c  memleap_macro.c  memleap_mtrace.c  readme.md
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ gcc -o memleap_hook memleap_hook.c  -ldl -g
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ ./memleap_hook
[+0x15cc]--->ptr:0x558c74d602a0 size:10
[+0x15da]--->ptr:0x558c74d606d0 size:20
[-0x15ea]--->ptr:0x558c74d602a0
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ cd mem
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件/mem$ ls
0x558c74d606d0.mem
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件/mem$ cat 0x558c74d606d0.mem
0x00000000000015da
main
/home/luffy/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件/memleap_hook.c:83
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件/mem$
90.mem
```


***memleap_mtrace.c***
```c
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ gcc -o memleap_mtrace memleap_mtrace.c
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ ./memleap_mtrace
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ export MALLOC_TRACE=./mtrace.log
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ ./memleap_mtrace
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ ls
mem  memleap_hook.c  memleap_macro  memleap_macro.c  memleap_mtrace  memleap_mtrace.c  mtrace.log
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ cat mtrace.log
= Start
@ ./memleap_mtrace:[0x560840c801c4] + 0x5608427f3690 0xa
@ ./memleap_mtrace:[0x560840c801d2] + 0x5608427f36b0 0x14
@ ./memleap_mtrace:[0x560840c801e0] + 0x5608427f36d0 0x1e
@ ./memleap_mtrace:[0x560840c801f0] - 0x5608427f3690
= End
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$ addr2line -f -e ./memleap_mtrace -a 0x560840c801d2
0x0000560840c801d2
??
??:0
luffy@luffy-server:~/share/0voice/linux-C-C-Study/3.2.5内存泄露检测组件$

```