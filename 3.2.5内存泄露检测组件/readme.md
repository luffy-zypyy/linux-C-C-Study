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

```


