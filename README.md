# MIPS-Simulator
a mips simulator 

compiled by visual studio 2010

以下文件：sim.cpp, computer.h, computer.cpp, proj1.cpp and proj1.h 组成了MIPS仿真器的一个框架. 通过在文件proj1.cpp中增加代码来完成整个程序。你的仿真器必须能仿真以下MIPS机器指令:

        addu    Rdest, Rsrc1, Rsrc2

        addiu   Rdest, Rsrc1, imm

        subu    Rdest, Rsrc1, Rsrc2

        sll     Rdest, Rsrc, shamt

        srl     Rdest, Rsrc, shamt

        and     Rdest, Rsrc1, Rsrc2

        andi    Rdest, Rsrc, imm

        or      Rdest, Rsrc1, Rsrc2

        ori     Rdest, Rsrc, imm

        lui     Rdest, imm

        slt     Rdest, Rsrc1, Rsrc2

        beq     Rsrc1, Rsrc2, raddr

        bne     Rsrc1, Rsrc2, raddr

        j       address

        jal     address

        jr      Rsrc

        lw      Rdest, offset (Radd)

        sw      Rsrc, offset (Radd)

框架代码

框架代码首先做下面这些事情.

1.      将机器码读入"内存", 从"地址" 0x00400000 处开始执行。(与MARS约定相同, 从0x0000000 到 0x00400000的地址未用) 假定程序的长度不超过1024个字。包含源代码的程序通过命令行给定.

2.      栈指针初始化为0x00404000, 其他所有寄存器初始化为0x00000000, 并将程序计数器（PC）初始化为0x00400000.

3.      数据内存的首地址为0x00401000，末地址为0x00404000. 在同一内存数组中存储数据和指令.

4.      设置用于管理整个程序如何与用户交互的标识（flags）.

然后，进行一个循环，反复取指和执行指令, 在程序运行中打印（printing）相关信息:

·         所执行的机器指令, 其地址，反汇编形式;

·         如果发现不支持的指令，disassembled（反汇编）程序应调用exit(0) i;

·         程序计数器（PC）的新值;

·         当前寄存器状态的信息;

·         内存内容的信息.

你的任务是编写disassembled （反汇编）和 simulateInstr（指令仿真）函数的代码, 当然可能还有一些相关的你希望用到的辅助函数的代码。可以假设仿真指令不会出现寻址错误. 如果程序遇到没有列出的指令，它将退出.

框架程序支持以下命令行选项:

  -i  
	

以 "交互interactive方式"运行代码. 在此模式下，仿真每个指令前，程序输出">"提示符，等待你输入回车继续。如果你输入"q" (意为"quit")加一个回车, 程序将退出. 如果不指定此选项, 终止程序的唯一方式是仿真一个上面没有列出的指令。

  -r  
	

在执行一个指令后列出所有寄存器的值. 当未指定此选项时, 只列出指令所影响的寄存器的值; 对于分支, 跳转, 写内存这些不影响任何寄存器的指令, 框架代码输出没有寄存器受影响的信息. (当仿真的指令不影响任何寄存器时，你的代码需要给出一个信号，方法是在changedReg 的参数中返回一个合适的值给simulate和simulateInstr.)

  -m  
	

在执行一个指令后列出所有包含非零值的内存地址的值. 当未指定此选项时, 只列出指令所影响的内存地址的指; 对于所有非sw指令，框架代码输出没有内存地址受影响的信息. (当仿真指令不影响内存时，你的代码需要给出一个信号，方法是在 changedMem 参数中返回一个合适的值给simulate和simulateInstr.)

  -d  
	

这是调试标识，你会发现它很有用的.

在框架代码中的几乎所有输出都是在printInfo 函数中完成的. 另外，disassembled 函数的结果(output)也会输出, 这需要特别注意。尽管只是以文本方式输出指令和操作数, 由于我们使用自动脚本来给你判分. 因此, 结果（output）必须严格遵守下面的说明。下面是详细的输出格式:

·         反汇编的指令的指令名后必须跟一个"跳格字符tab" (C语言中字符为'\t'), 指令后的各项用逗号+空格来分隔.

·         对指令addiu, srl, sll, lw 和sw, 立即数的值必须以十进制数输出 (如果为负数，前面要有负号) 不能有前导0，除非为0 (输出0).

·         对指令andi, ori, 和lui, 立即数必须为十六进制, 且前面有0x，并且没有前导0，除非值为0 (输出0x0).

·         对于分支和跳转指令, 目标地址必须以完整的8位16进制数输出, 包含前导0. (请注意此格式和分支跳转汇编语言指令的区别) 最后, 分支和跳转的目标地址必须为绝对地址，而不是与PC相关的.

·         所有16进制值必须使用小写字母，且没有前导0x.

·         参数字段之间的分隔为逗号+空格.

·         寄存器以数字方式指定, 没有前导0 (如$10 and $3) ，而不能以名字方式给定(如$t2).

·         以存储字节(sb)指令为例，需要返回"sb\t$10, -4($21)".

·         你有责任管理所有你返回字符串关联的内存. 如果使用malloc(), 其后你需要以某种方式调用free() 来释放内存 (注意不能修改computer.cpp). 提示: 静态或全局变量.

·         如果lw 或sw 指令访问无效内存地址, 你的代码必须输出和computer.cpp中的contents()函数完全相同的错误信息，然后调用exit(0)

以下是正确(good)的指令示例:

        addiu     $1, $0, -2

        lw        $1, 8($3)

        srl       $6, $7, 3

        ori       $1, $1, 0x1234

        lui       $10, 0x5678

        j         0x0040002c

        bne       $3, $4, 0x00400044

以下是错误(bad)指令的示例:

        addiu     $1, $0, 0xffffffff     # addiu不应输出16进制

        sw        $1, 0x8($3)            # sw不应输出16进制

        sll       $a1, $a0, 3            # 应使用寄存器号，而不是寄存器名

        srl       $6,$7,3                # 参数间缺空格

        ori       $1 $1 0x1234           # 缺逗号

        lui       $t0, 0x0000ABCD        # 16进制数应该小写且not zero extended

        j         54345                  # 地址应为16进制

        jal       00400548               # 缺前导0x

        bne       $3, $4, 4              # 需要完整的16进制目标地址

文件sample.s和sample.output 中提供了一个输出示例，你可以用它来做一个基本测试"sanity check". 我们没有提供其他输入测试文件. 你必须自己在编写MIPS汇编测试用例, 使用MARS (mars-cs61c)来汇编, 然后输出（dump）二进制代码. 参见"提示"中关于如何做的建议.

编写测试用例

测试的第一步是用MIPS汇编语言编写测试程序. 下面是如何编写MIPS测试代码的一些重要指南:

·         深吸一口气，忘记你要编写一个模拟器。编写一个简单、短小、并且有意义的MIPS程序。程序越有意义, 越容易检验仿真器能工作。

·         显然，编写测试代码时应只使用已经支持的指令。

·         我们的仿真器中，程序从内存地址0x400000开始，数据从内存地址0x401000开始，栈始于0x00404000。 MARS初始化栈指针为0x7ffffeffc. 当编写测试程序时，请确保此差异不会产生问题。

·         MARS将跟随在汇编指示器.data 后的所有内容顺序放到内存中。但这不会反映到MARS dumps出来的二进制文件中。此dump文件将只包含指令。因此，在使用MARS时，MARS会帮你把数据装入到内存中，现在你必须用指令自己装入。

举例来说，假定你想编写一个MIPS程序foo，该程序使用5个字的数组，数组元素初始化为整数1, ..., 5. 正常的情况下，你应该编写象如下形式的代码:

         .data

  foo:    .word 1,2,3,4,5

本项目, 你不能使用.data段. 取而代之的是你应该让你的程序来初始化数组:

  __start:

       lui     $t0, 0x1001

       ori     $t0, 0x0000

       addiu   $t1, 1

       sw      $t1, 0($t0)

       addiu   $t1, 2

       sw      $t1, 4($t0)

       addiu   $t1, 3

       sw      $t1, 8($t0)

       addiu   $t1, 4

       sw      $t1, 12($t0)

       addiu   $t1, 5

       sw      $t1, 16($t0)

你也可以使用循环来完成。这看来是件麻烦又花时间的事，但它将大大减化模拟器编程.

·         确知测试用例的结果. 例如, 如果测试程序从内存的一块区域复制一段数据到另一块区域, 在程序结束后，你应该知道需要看内存的哪一段来验证是否正确。命令行参数-r, -m, 和 -c 对产生正确的结果很有用，它能为模拟器提供正确性的依据.
生成二进制文件

可以直接为模拟器生成过程. 以下是步骤:

1.      用MIPS汇编编写测试程序. 确保只使用所支持的指令, 不要使用汇编指示来建立.data 内存. 假定你的测试文件命名为test0.s. 使用单个不支持的指令(如slti)来终止程序. 如前所述, 执行不支持的指令将使模拟器退出.

2.      在你的机器上使用Mars到你的本机上.

3.      使用MARS调试你的MIPS代码.

4.      Dump the code from MARS using the Save Dump button in the lower left of the data segment window.  Be sure to select the .text segment in the dropdown before doing this, or you might accidentally dump the data memory. You should also select the Binary dump format for this project.  MARS will dump the binary instruction into a file of your choosing.

5.      Now, test0.dump is a valid input to the simulator. We recommend that you save all of your .s and .dump test files in an orderly fashion. This way, when you think you are done with the simulator, you will have a comprehensive battery of tests to put it through before submitting. 
