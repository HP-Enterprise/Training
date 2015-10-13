#������  �����ű�����֪ʶ��ԭ����ο� [Chapter 6. Build Script Basics](https://docs.gradle.org/current/userguide/tutorial_using_tasks.html)��

##6.1 ���̺�����

Gradle�е��������ݶ��ǻ���**����**��**����**��������������֮�ϵġ�

ÿһ��Gradle�Ĵ���������һ������������ɵġ�һ�����������������ȡ������ʹ��Gradle�������Ĺ��������磺һ�����̿��ܴ�����һ��Jar��������һ��WebӦ�á���Ҳ�����������������ɵ�һ���ɶ��Jar����ɵ�ZIP�����ļ���һ������û�б�Ҫ��һ���Ѿ��������Ķ��������������Ѿ���ɵģ����磺�����Ӧ�ó�����һ��վ�������������������⿴�����ƺ��е�ģ�������ġ�Gradle�Ŀ�ݴ���֧��(build-by-convention support)Ϊ���̵ĸ���������һ����Ϊ����Ķ��塣

ÿһ����������һ������������ɵġ�һ���������һ����������ִ�е�ĳ�����ɷָ��ԭ�Ӳ���������������Ǳ���ĳЩ�࣬����һ��Jar��������javadoc�ļ���������ĳ������ֿⷢ��ĳЩ�ļ���

���ڣ����ǽ�Ҫ��һ�����̵Ĺ��������ж���һЩ�򵥵����񡣽��������½ڽ������ؽ����ڹ��������ʹ�ö๤���Լ��๤�̺Ͷ�����Ľ�ϡ�

##6.2 Hello World

�����ͨ��ʹ�� `gradle` ����������һ��Gradle��Ŀ��`gradle` ������ڵ�ǰĿ¼��Ѱ���ļ���Ϊbuild.gradle���ļ�������ͨ������� `build.gradle` �ļ���֮Ϊ���ǽ�Ҫ�����Ĺ����ű��������ϸ���˵��Ӧ����һ���������ýű�.��������ű�������һ�����̺��������������������

�Ͻ��������´���������ʾ��Ϊ `build.gradle` �Ĺ����ű��ɡ�

**�� 6.1. ��ĵ�һ�������ű�**

**build.gradle**
```javascript
task hello {
    doLast {
        println 'Hello world!'
    }
}
```

��������ģʽ�£����뵽�ýű��ļ���Ŀ¼����ͨ��ʹ������ `gradle -q hello` ��ִ�У�

**�� 6.2. ִ��һ�������ű�**

���� **`gradle -q hello`** �����������ʾ��
```javascript
> gradle -q hello
Hello world!
```

�⾿����������е��أ���������ű�������һ������hello�ĵ������Ҹ��������һ����������������gradle hello����ʱ��Gradle��ִ��hello������˳��ִ�����а����Ķ��������������ֻ��һ����һЩ��ִ�е�groovy������ɵ���ֹ�������ӡ�� `Hello world��` ��

�������Ϊ�⿴�����ƺ��� `Ant's targets` ���ƣ���ô��ϲ�����ˡ�Gradle������ȼ��� `Ant's targets`�����������㽫Ҫ������һ����`Gradle tasks` ���ܸ�Ϊǿ������� `Ant` ����ʹ����һ����ͬ������ `task` ������ `target`����Ϊ������Ϊ `task` ���������� `target` ����ӵ����˼�����̡����ҵ������������һ���� `Ant` �������ͻ����Ϊ `Ant` ���������� `commands` ���� `javac` �� `copy` ��Ϊ���� `task` �����Ե�̸������ʱ����������ָ������ `Ant's targets` �ȼ۵� `Gradle tasks` ���������Ҫ���� `Ant tasks(Ant commands)` �����ǻ���ȷ��˵ `Ant task` ��

```
What does -q do?

Gradle ������ -q ����Ϊ�Σ�
������û�ָ���еĴ󲿷������е����ж�ʹ����-q��������в���������Ϊ������Gradle����־��Ϣ�������Ϳ���ֻ��ʾ�����������ݡ�ʹ�ø��û�ָ���е����������ʾ��Ϊ��ࡣ��Ȼ���������ȥ��-q���������hello����
����㲻����-q����ô�Ϳ��Թ��ϵز��á�
```
��Ҫ�˽�������Ӱ��Gradle����������в������Բ鿴 [Chapter 17, Logging](https://docs.gradle.org/current/userguide/logging.html) ��

##6.3 ����һ�����������

����һ�����ٶ���һ�������������hello����ķ�����������Ϊ�ļ�ࡣ������ʾ��

**�� 6.3. ����������**

**build.gradle**
```
task hello << {
    println 'Hello world!'
}
```

��һ�ζ�����һ��ֻ��һ����ִ�еĵ���ֹ������ `hello ` �������ǽ���������û�ָ��ȫ��ʹ����������Ķ��巽ʽ��

##6.4 �����ű��Ĵ�������

Gradle�����ű�ʹ���ܹ����ʹ��Groovy���ԡ���Ϊһ����θС�ˣ�һ������������������ӣ�

**�� 6.4. ��Gradle��������ʹ��Groovy����**

**build.gradle**
```
task upper << {
    String someString = 'mY_nAmE'
    println "Original: " + someString 
    println "Upper case: " + someString.toUpperCase()
}
```

���� **`gradle -q upper`** �����������ʾ��
```
> gradle -q upper
Original: mY_nAmE
Upper case: MY_NAME
```

**�� 6.5. ��Gradle��������ʹ��Groovy����**

**build.gradle**
```
task count << {
    4.times { print "$it " }
}
```

���� **`gradle -q count`** �����������ʾ��
```
> gradle -q count
0 1 2 3 
```

##6.5 ��������

����������Ѿ����뵽�ģ����������һ���������ȴ��������������������

**�� 6.6. �������������**

**build.gradle**
```
task hello << {
    println 'Hello world!'
}
task intro(dependsOn: hello) << {
    println "I'm Gradle"
}
```

���� **`gradle -q intro`** �����������ʾ��
```
> gradle -q intro
Hello world!
I'm Gradle
```

��������ʱ�����Ӧ������û�б�Ҫ���Ѿ����ڵģ����Ժ��涨��һ���µ�����

**�� 6.7. ������ ���� ����������Բ������Ѵ��ڵ�**

**build.gradle**
```
task taskX(dependsOn: 'taskY') << {
    println 'taskX'
}
task taskY << {
    println 'taskY'
}
```

���� **`gradle -q taskX`** �����������ʾ��
```
> gradle -q taskX
taskY
taskX
```

����taskY��taskX������������taskXȴ����taskY������֮ǰ�����ġ�����ڹ����๤���Ǻ���Ҫ�ġ���Ҫ�˽��������������������֪ʶ���Բ鿴 [Section 14.4, ��Adding dependencies to a task��](https://docs.gradle.org/current/userguide/more_about_tasks.html#sec:adding_dependencies_to_tasks)��

**��ע��**������Ҫ����һ����δ���������ʱ��������ʹ�ÿ�ݷ��ţ��������Ķ� [Section 6.8, ��Shortcut notations��](https://docs.gradle.org/current/userguide/tutorial_using_tasks.html#sec:shortcut_notations)����

##6.6 ��̬����

ʹ��ǿ��� `Groovy` ���Բ��������Զ���һ������Ҫ��ɵĶ������������ܶ��������¡����磬�����ʹ��������̬��������

**�� 6.8. ����Ķ�̬����**

**build.gradle**
```
4.times { counter ->
    task "task$counter" << {
        println "I'm task number $counter"
    }
}
```

���� **`gradle -q task1`** �����������ʾ��
```
> gradle -q task1
I'm task number 1
```

##6.7 �����Ѷ��������

����һ���������Ϳ���ͨ��һ�� `API` �����ʵ��á����磬�����ʹ��������̬��һ���������е��������������Ȼ��Antȴ�������������������鷢����

**�� 6.9. ͨ��API�����ʵ���һ������ ���� �������**

**build.gradle**
```
4.times { counter ->
    task "task$counter" << {
        println "I'm task number $counter"
    }
}
task0.dependsOn task2, task3
```

���� **`gradle -q task0`** �����������ʾ��
```
> gradle -q task0
I'm task number 2
I'm task number 3
I'm task number 0
```

�����㻹���Ը�һ���Ѷ�������������Ϊ��

**�� 6.10. ͨ��API�����ʵ���һ������ ���� �����Ϊ**

**build.gradle**
```
task hello << {
    println 'Hello Earth'
}
hello.doFirst {
    println 'Hello Venus'
}
hello.doLast {
    println 'Hello Mars'
}
hello << {
    println 'Hello Jupiter'
}
```

���� **`gradle -q hello`** �����������ʾ��
```
> gradle -q hello
Hello Venus
Hello Earth
Hello Mars
Hello Jupiter
```

��� `doLast` �� `doFirst` ���Ա�ִ�ж�Ρ����������������еĿ�ʼ���β���һ�����������������ִ��ʱ�������б��е���Щ�������ᱻ˳��ִ�С���� `<<` ����ֻ�� `doLast` ��һ��������

##6.8 ��ݷ���

�����������ǰ���������ע�⵽�ģ���һ��������ķ�����������һ���Ѵ��ڵ�����ÿһ��������Ϊ�����ű������Զ�����Ч�ġ�

**�� 6.11. ���ʵ�����Ϊ�����ű����Ե�����**

**build.gradle**
```
task hello << {
    println 'Hello world!'
}
hello.doLast {
    println "Greetings from the $hello.name task."
}
```

���� **`gradle -q hello`** �����������ʾ��
```
> gradle -q hello
Hello world!
Greetings from the hello task.
```

��ʹ�ô����к�ǿ�Ŀɶ��ԣ��ر��ǵ�ʹ��һЩ�в���ṩ�ĵ�����ʱ�������������

##6.9 �Զ�����������

����Ը�һ������������Զ������ԡ����һ����ΪmyProperty�����ԣ�ʹ�� `ext.myProperty` �������Եĳ�ʼֵ���Ӹö����п�ʼ���������ǿɶ��Ĳ��ҿ���������һ��Ԥ������������ԡ�

**�� 6.12. ��������Զ�������**

**build.gradle**
```
task myTask {
    ext.myProperty = "myValue"
}

task printTaskProperties << {
    println myTask.myProperty
}
```

���� **`gradle -q printTaskProperties`** �����������ʾ��
```
> gradle -q printTaskProperties
myValue
```

�Զ������Զ���������û�����Ƶġ���Ҫ�˽�������Ķ� [Section13.4.2,��Extra properties��](https://docs.gradle.org/current/userguide/writing_build_scripts.html#sec:extra_properties)��

##6.10 ʹ�� Ant Tasks

��Gradle�� `Ant tasks` �Ǻ�����ģ�����˵��һ���ļ�����GradleΪ `Ant tasks` �ṩ�˷ǳ���������ϣ���ʵ������������ֻ�Ǽ򵥵������� `Groovy` ���ԡ��ǳ������ `AntBuilder` Ϊ `Groovy` �����ṩ�˺ܺõ�֧�֡���Gradle��ʹ�� `Ant tasks` ����ڴ�һ�� `build.xml` �ļ�����һ���ķ��㲢�Ҹ��ӵع���ǿ�󡣴����������У������ѧ�����ִ�� `Ant tasks` �� ��η���ʹ�� `Ant properties`��

**�� 6.13. ʹ��AntBuilderִ��ant.loadfile�ļ�**

**build.gradle**
```
task loadfile << {
    def files = file('../antLoadfileResources').listFiles().sort()
    files.each { File file ->
        if (file.isFile()) {
            ant.loadfile(srcFile: file, property: file.name)
            println " *** $file.name ***"
            println "${ant.properties[file.name]}"
        }
    }
}
```

���� **`gradle -q loadfile`** �����������ʾ��
```
> gradle -q loadfile
 *** agile.manifesto.txt ***
Individuals and interactions over processes and tools
Working software over comprehensive documentation
Customer collaboration  over contract negotiation
Responding to change over following a plan
 *** gradle.manifesto.txt ***
Make the impossible possible, make the possible easy and make the easy elegant.
(inspired by Moshe Feldenkrais)
```

��Ȼ����Ĺ����ű���ʹ�� `Ant` �㻹�������ܶ������Ĺ�������ϸ��Ϣ���Ķ� [Chapter 16, Using Ant from Gradle](https://docs.gradle.org/current/userguide/ant.html) ��

##6.11 ���÷���

Gradle�������֯�������߼��������Լ��ĺ�����׼����������ӵĹ����߼��ĵ�һ��ˮƽ���ǳ�ȡһ��������

**�� 6.14. ʹ�÷�����֯�����߼�**

**build.gradle**
```
task checksum << {
    fileList('../antLoadfileResources').each {File file ->
        ant.checksum(file: file, property: "cs_$file.name")
        println "$file.name Checksum: ${ant.properties["cs_$file.name"]}"
    }
}

task loadfile << {
    fileList('../antLoadfileResources').each {File file ->
        ant.loadfile(srcFile: file, property: file.name)
        println "I'm fond of $file.name"
    }
}

File[] fileList(String dir) {
    file(dir).listFiles({file -> file.isFile() } as FileFilter).sort()
}
```

���� **`gradle -q loadfile`** �����������ʾ��
```
> gradle -q loadfile
I'm fond of agile.manifesto.txt
I'm fond of gradle.manifesto.txt
```

�����㽫�ῴ���ڶ๤�̵���Ŀ���������ķ����ǿ��Ա��ӹ��̹���ʹ�õġ������Ĺ����߼���úܸ���ʱ��Gradle�����ṩ���������ӷ���ķ�������֯����Ϊ������һ��������ϸ������֯�������������Ķ� [Chapter 62, Organizing Build Logic](https://docs.gradle.org/current/userguide/organizing_build_logic.html) ��

##6.12 Ĭ������

Gradle�����㶨��һ������Ĭ��������Щ�������û��ָ��ִ����������ʱִ�С�

**�� 6.15. ����һ��Ĭ������**

**build.gradle**
```
defaultTasks 'clean', 'run'

task clean << {
    println 'Default Cleaning!'
}

task run << {
    println 'Default Running!'
}

task other << {
    println "I'm not a default task!"
}
```

���� **`gradle -q`** �����������ʾ��
```
> gradle -q
Default Cleaning!
Default Running!
```

������������൱���������� **`gradle clean run`** ����һ���๤�̵Ĺ����У�ÿһ���ӹ��̶����Զ������Լ���Ĭ���������һ���ӹ���û��ָ��ִ�е�Ĭ��������ô����ʹ�����ĸ�����Ĭ��������������̶�����Ĭ�����񣩡�

##6.13 DAG����

�������Ǻ������ϸ���۵ģ�������ο� [Chapter 58, The Build Lifecycle](https://docs.gradle.org/current/userguide/build_lifecycle.html)����Gradle��һ�������ں�һ��ִ���ڡ���Gradle��������ɺ�Gradle����֪������Ӧ�ñ�ִ�е�����GradleΪ���ṩ��һ�����Ӻ��������������Щ��Ϣ����Щ��Ϣʹ�õķ���֮һ���Ǽ����ָ����Ҫ���е������Ƿ�����Щ��Ҫ��ִ�е������С�������Щ��Ϣ������Ը�һЩ�������費ͬ��ֵ��

������������ӵ��У����� `distribution` ������ `release` ��ִ�лᵼ�°汾�������в�ͬ��ֵ��

**�� 6.16. ����ѡ������Ĳ�ִͬ�еĽ���಻ͬ**

**build.gradle**
```
task distribution << {
    println "We build the zip with version=$version"
}

task release(dependsOn: 'distribution') << {
    println 'We release now'
}

gradle.taskGraph.whenReady {taskGraph ->
    if (taskGraph.hasTask(release)) {
        version = '1.0'
    } else {
        version = '1.0-SNAPSHOT'
    }
}
```

���� **`gradle -q distribution`** �����������ʾ��
```
> gradle -q distribution
We build the zip with version=1.0-SNAPSHOT
```

���� **`gradle -q release`** �����������ʾ��
```
> gradle -q release
We build the zip with version=1.0
We release now
```

����Ҫ���������������releaseִ��ǰ����release�ѱ� `whenReady` Ӱ��ı䡣��ʹ������release������Ҫ������Ҳ����Ч�ġ�

##6.14 ��������ѧʲô��

�ڱ����У����Ǽ򵥵��˽���һ��gradle������ơ������Ⲣ���������������Ľ������������Ҫ�˽������������֪ʶ����ο� [Chapter 14, More about Tasks](https://docs.gradle.org/current/userguide/more_about_tasks.html) ��

���У��������㽫Ҫѧ������ [ Chapter 7, Java Quickstart](https://docs.gradle.org/current/userguide/tutorial_java_projects.html)��[Chapter 8, Dependency Management Basics](https://docs.gradle.org/current/userguide/artifact_dependencies_tutorial.html) ��