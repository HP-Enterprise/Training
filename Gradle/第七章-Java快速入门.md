# ������ Java��������[Chapter 7. Java Quickstart](https://docs.gradle.org/current/userguide/tutorial_java_projects.html)
##7.1 Java���

����������֪��Gradle��һ��ͨ�õĹ������ߡ����������Թ����κ������ڹ����ű���ʵ�ֵĶ�����Ȼ�����������ڹ����ű�����Ӵ������Gradle�������κ����顣

�ͻ���������˵���󲿷�Java��Ŀ��ʮ�����ƣ�����Ҫ�������JavaԴ���ļ�������һЩ��Ԫ���Բ��Ҵ���һ��JAR�ļ����������class�ļ�������㲻��ҪΪÿһ����Ŀ����Щ���飬�ǽ���һ����������顣���˵��ǣ�����Ĳ���Ҫ��Groovyͨ��ʹ�ò�������������⡣�����Gradle����չ������ĳ�ַ�ʽ���������Ŀ�����͵����������һЩԤ�����ú�������ĳЩ���������task��Gradle�������������һ�𣬲�������Ժܼ򵥵ر�д���Լ��Ĳ������������ˡ�����һ�ֲ������ **Java���**����������������task�������Ŀ�У���Щtask�����Ͳ������JavaԴ�룬���Ұ��������JAR�ļ���

Java����ǻ���Լ���ġ�����ζ������Ŀ����෽��ò��������Ĭ��ֵ������JavaԴ��Ӧ�÷��������������Ŀ����Լ��������Ĺ����ű�����ͨ������Ҫ��̫�������Ϳ������һ�����õĹ����������ĳЩ�ط��㲻����޷���ѭ���Լ����Gradle�����㶨�������Ŀ����ʵ�ϣ���Ϊ��Java��Ŀ��֧������һ���������ʽ��ʵ�ֵģ�����㲻��Ļ������������Ҫ�ڹ���Java��Ŀʱʹ����������

��֮����½��У�����������й�Java�������������Ͷ���Ŀ�������ӵ�����̽�֡��ڱ�����������Ҫ����һ���й����ʹ��Java�������Java��Ŀ�ĳ������

##7.2 һ��������Java��Ŀ

����������һ���򵥵����ӡ���Ҫʹ��Java���������������ݵ���Ĺ����ļ��У�

**ʾ�� 7.1. ʹ��Java���**

**build.gradle**

```groovy
    apply plugin: 'java'
```
ע�⣺���ʾ����ʹ�õ�Դ�������Gradle��װĿ¼�µ�samples/java/quickstartĿ¼���ҵ���

������㶨��һ��Java��Ŀ����Ҫ���ġ��⽫��Ӧ��Java����������Ŀ�У��������һЩtask�������Ŀ�С�

Gradle��������src/main/javaĿ¼���ҵ������ĿԴ�룬��src/test/javaĿ¼���ҵ�����Դ�롣���⣬��src/main/resourcesĿ¼�µ��κ��ļ����ᱻ��Ϊ��Դ�ļ���ӵ�JAR�ļ����src/test/resourcesĿ¼�µ��κ��ļ����ᱻ��ӵ�classpath���������в��ԡ����е�����ļ�����������buildĿ¼�����JAR�ļ���build/libsĿ¼�

###7.2.1 ������Ŀ

Java�����������൱���task��������Ŀ��Ȼ�����㹹����Ŀ��ʱ��ֻ��Ҫ������task���õ����ձ��task����build task������������������������Ŀ���������� **gradle build**��Greadle�������Ͳ�����Ĵ��룬����һ��JAR�ļ����������Ҫclass����Դ�ļ���
 
**ʾ��7.2.����һ��java��Ŀ**

**����gradle build�����**

```groovy
    > gradle build
    :compileJava
    :processResources
    :classes
    :jar
    :assemble
    :compileTestJava
    :processTestResources
    :testClasses
    :test
    :check
    :build
```
 ```groovy   
    BUILD SUCCESSFUL
```
```groovy   
    Total time: 1 secs
```

һЩ�������õ�task�ǣ�

**clean**
    
    ɾ��buildĿ¼���Ƴ����еĹ����ļ���
    
**assemble**
    
    ����ʹ����Ĵ��룬���ǲ������е�Ԫ���ԡ������Ĳ������Ӹ����artifacts�����task����磬�����ʹ��War��������task�ͻṹ��WAR�ļ��������Ŀ�
    
**check**

    ����Ͳ�����Ĵ��롣�����Ĳ������Ӹ����check�����task����磬�����ʹ��checkstyle��������task��������Դ��������Checkstyle��
    

###7.2.2 �ⲿ����

ͨ����һ��Java��Ŀ���������ܶ��ⲿ��JAR�ļ����漰�������JAR�ļ�������Ҫ����Gradle�������ҵ����ǡ���Gradle���棬artifactλ��һ���ֿ��о���JAR�ļ�������ֿ����������ȡ��Ŀ��Ҫ���ⲿ�����ļ������߷�����Ŀ��artifact����������һ����Ϊ���ӣ����ǽ���ʹ�ù�����Maven�⣺

**ʾ��7.3.���Maven��**

**build.gradle**

```groovy
    repositories {
        mavenCentral()
    }
```

�����������һЩ�ⲿ��������������ǻ��������ǵ�class����һ������commons collections�ı���ʱ�������������ǵ�test class����һ������junit�ı���ʱ������

**ʾ��7.4.�������**

**build.gradle**

```groovy
    dependencies {
        compile group: 'commons-collections', name: 'commons-collections', version: '3.2'
        testCompile group: 'junit', name: 'junit', version: '4.+'
    }
```

������ҵ����������ڵڰ��£��������������[Chapter 8, Dependency Management Basics](https://docs.gradle.org/current/userguide/artifact_dependencies_tutorial.html)

###7.2.3 ������Ŀ

Java��Ŀ����˺ܶ����Ե������Ŀ��ȥ����Щ���ԵĻ���Ĭ��ֵͨ�����㹻������Ŀ�������ЩĬ��ֵ���ʺϵĻ�Ҳ������ȥ���ġ�����������һ��������ӡ����������ǻ��������ǵ�Java��Ŀ�汾�ţ��Լ����ǵ�Դ�����ĸ��汾��Java��д�ġ����ǻ������һЩJAR manifest���ԡ�

**ʾ��7.5.����MANIFEST.MF**

**build.gradle**

```groovy
    sourceCompatibility = 1.5
    version = '1.0'
    jar {
        manifest {
            attributes 'Implementation-Title': 'Gradle Quickstart',
                       'Implementation-Version': version
        }
    }
```

ava plugin��ӵ�task���й��ɵ�task��ȷ�еľ������Ǻ������ڹ����ļ���������һ��������ζ�������ʹ���κ���֮ǰ������ʾ�Ľṹ��������Щtask�����磬���������task�����ԣ����task����Ϊ���޸�task��������������ȫ�滻��task�������ǵ������У����ǽ�������test task������Test��һ�֣�ͨ�������ʽ�����в��Ե�ʱ�����һ��ϵͳ���ԣ�

**ʾ��7.6.���һ��ϵͳ����**

**build.gradle**

```groovy
    test {
        systemProperties 'property': 'value'
    }
```

###7.2.4 ����һ��JAR�ļ�

ͨ��JAR�ļ���Ҫ������ĳһ���ط��������Ļ��������Ҫ����Gradle�����﷢����ЩJAR�ļ�����Gradel���棬artifacts������JAR�ļ������������ֿ�����������������ǽ��ᷢ��һ������Ŀ¼����Ҳ���Է�����Զ�̣����߶����ַ��

**ʾ��7.7.����JAR�ļ�**

**build.gradle**

```groovy
uploadArchives {
    repositories {
       flatDir {
           dirs 'repos'
       }
    }
}
```

���� **gradle uploadArchives**����������JAR�ļ���


###7.2.5 ����һ��Eclipse��Ŀ

��Ҫ����Eclipse����Ŀ˵���ļ�������.project������Ҫ��������������Ĺ����ļ��У�

**ʾ�� 7.8. Eclipse���**

**build.gradle**

```groovy
    apply plugin: 'eclipse'
```

����gradle eclipse����������Eclipse��Ŀ�ļ�����Ҫ��ȡ�����й�eclipse task����Ϣ���Բ���[��38�£�Eclipse���](https://docs.gradle.org/current/userguide/eclipse_plugin.html)��

###7.2.6 �ܽ�

���������ǵ����ӵ����������ļ���

**ʾ�� 7.9. Java���� - �����Ĺ����ļ�**

**build.gradle**

```groovy
    apply plugin: 'java'
    apply plugin: 'eclipse'
    
    sourceCompatibility = 1.5
    version = '1.0'
    jar {
        manifest {
            attributes 'Implementation-Title': 'Gradle Quickstart',
                       'Implementation-Version': version
        }
    }
    
    repositories {
        mavenCentral()
    }
    
    dependencies {
        compile group: 'commons-collections', name: 'commons-collections', version: '3.2'
        testCompile group: 'junit', name: 'junit', version: '4.+'
    }
    
    test {
        systemProperties 'property': 'value'
    }
    
    uploadArchives {
        repositories {
           flatDir {
               dirs 'repos'
           }
        }
    }
```

##7.3 ��������Ŀ

����������һ�����͵Ķ���Ŀ��������������Ŀ�Ľṹ��

**ʾ�� 7.10. ����Ŀ���� - �ֲ㲼��**

Build layout�������ṹ��

```groovy
    multiproject/
      api/
      services/webservice/
      shared/
      services/shared/
```

ע�⣺��Gradle��װĿ¼�µ�samples/java/multiprojectĿ¼������ҵ�Դ�롣

�������У��������ĸ���Ŀ����Ŀapi�����һ��JAR�ļ���webserviceʹ�á���Ŀwebservice��һ������XML�ļ���webapp����Ŀshared������api��webserviceҪ�õ��Ĵ��롣��Ŀservices/shared/�Ĵ���������shared��

###7.3.1 ����һ������Ŀ����

��Ҫ����һ������Ŀ����������Ҫ����һ�������ļ�����������ļ�λ����Ŀ���ĸ�Ŀ¼������ָ����Щ��Ŀ�������ڹ����С��������ļ����뱻����Ϊsettings.gradle���ڱ������У�����ʹ����һ���򵥵ķֲ㲼�֡���������ò����һ�µ������ļ�

**ʾ�� 7.11. ����Ŀ���� - settings.gradle�ļ�**

**settings.gradle**

```groovy
    include "shared", "api", "services:webservice", "services:shared"
```

�������[��59�£� ����Ŀ����](https://docs.gradle.org/current/userguide/multi_project_builds.html)���ҵ������й������ļ�����Ϣ��

###7.3.2 ͨ������

���ڴ��������Ŀ������˵��������һЩ���ö���ÿһ����Ŀ����ͨ�õġ������ǵ���������ǽ���ʹ��һ�ֱ���������ע�似���ڸ���Ŀ�ﶨ��ͨ�����á�����Ŀ������Ŀ�����ĸ�Ŀ¼������һ����������subprojects��������������ڵ�ÿһ��Ԫ�أ�������Ŀ��Ȼ��������Ϣע�����С�ͨ�������ʽ�����ǿ��Ժ����׵�Ϊÿһ���ļ�ע�����ú�һЩͨ��������

**ʾ�� 7.12. ����Ŀ���� - ͨ������**

**build.gradle**

```groovy
    subprojects {
        apply plugin: 'java'
        apply plugin: 'eclipse-wtp'
    
        repositories {
           mavenCentral()
        }
    
        dependencies {
            testCompile 'junit:junit:4.12'
        }
    
        version = '1.0'
    
        jar {
            manifest.attributes provider: 'gradle'
        }
    }
```

��Ҫע��������ǵ������ｫJava���Ӧ����ÿһ������Ŀ������ζ���������������濴����task������������ÿһ������Ŀ�ﶼ�ǿ��õġ�����������ڸ�Ŀ¼����gradle build���������롢���Ժʹ�����е�����Ŀ��

�㻹Ҫע�������Щ�������Ӧ��������Ŀ�ڲ�����������Ŀ¼�������㲻Ӧ�øø�Ŀ¼�����κε�JavaԴ�ļ���ֻ��������Ŀ���Դ�ļ���

###7.3.3 ��Ŀ֮���������ϵ

�������ͬһ������֮���������Ŀ֮�������������һ����Ŀ���ɵ�JAR�ļ�������������һ����Ŀ����api��Ŀ�Ĺ����ļ������ǽ������һ��shared��Ŀ���������������������������Gradle����֪���ڹ���api��Ŀ֮ǰ�����ȹ���shared��Ŀ��

**ʾ�� 7.13. ����Ŀ���� - ��Ŀ�������**

**api/build.gradle**

```groovy
    dependencies {
        compile project(':shared')
    }
```

����[��59�� 7.1�ڣ�ʹ��Ŀ������Ч](https://docs.gradle.org/current/userguide/multi_project_builds.html#disable_dependency_projects)���˽�����øù�����Ч��

###7.3.4 �������а�

����Ҳ��Ҫ���һ�����а����͵��ͻ��ˣ�

**ʾ��7.14.����Ŀ�������а��ļ�**

**api/build.gradle**

```groovy
    task dist(type: Zip) {
        dependsOn spiJar
        from 'src/dist'
        into('libs') {
            from spiJar.archivePath
            from configurations.runtime
        }
    }
    artifacts {
       archives dist
    }
```

##7.4 ��һ��ȥ�ģ�

�ڱ��£����Ѿ�֪���˹���һ��������Java������Ŀ�ձ�Ҫ�������飬����½ڻ������꾡�����Java��Ŀ��Gradle���滹�������ܶ�����ġ�������ҵ��������Java�����֪ʶ�ڵڶ�ʮ���� Java���[Chapter 23, The Java Plugin](https://docs.gradle.org/current/userguide/java_plugin.html),�����������Gradle��װĿ¼ *samples/java*���ҵ�����java��Ŀ�����ӡ�

���⣬�����Ǽ���ѧϰ[�ڰ��£������������](https://docs.gradle.org/current/userguide/artifact_dependencies_tutorial.html)��