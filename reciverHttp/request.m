clc
clear all

serverNameXAngle = "http://192.168.4.1/XAngle";
serverNameYAngle = "http://192.168.4.1/YAngle";
serverNameZAngle = "http://192.168.4.1/ZAngle";

%a = arduino('COM3','Uno');

a=arduino('COM3','Uno');
chwytak=servo(a,'D2');
lokiec=servo(a,'D3');
bark=servo(a,'D4');
podstawa=servo(a,'D5');


while true
    str = webread(serverNameYAngle);
    value = (str2double(str)+90)/180;
    if(value>=0.99)
        value=0.99;
    end
    if(value<=0.01)
        value=0.01;
    end

    disp(str);
    disp(value);
    writePosition(podstawa, value);
    

    writePosition(chwytak, 0.5);

    writePosition(lokiec, 0.7);

    str = webread(serverNameXAngle);
    value = (str2double(str)+180)/360;
    if(value>=0.88)
        value=0.88;
    end
    if(value<=0.45)
        value=0.45;
    end
    writePosition(bark, value-0.1);

    
    pause(0.01);
end
