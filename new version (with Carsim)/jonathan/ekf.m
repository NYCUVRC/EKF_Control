syms Ts x1 x2 x3 theta w a q r
theta = 0;
Ts = 0.001;
x1 = 0; x2 = 0; x3 = 0;
w = 2; a = 1.5;
%q =0.01; r = 1

A = [1 Ts*x3 Ts*x2; -Ts*x3 1 -Ts*x1; 0 0 0];
B = [Ts 0 0; 0 Ts 0; 0 0 1];
H = [cos(theta) sin(theta) -w*cos(theta)/2+a*sin(theta); cos(theta) sin(theta) w*cos(theta)/2+a*sin(theta); 1 0 -w/2; 1 0 w/2];
Q = [q 0 0;0 q 0;0 0 q];
R = [r 0 0 0; 0 r 0 0; 0 0 r 0; 0 0 0 r];
P = [0 0 0; 0 0 0; 0 0 0];
x = [x1; x2; x3];
z = [0; 0; 0; 0];
u = [0; 0; 0];
disp(x);



for t=0:2
    x = A*x+B*u;
    P = A*P*A' + Q;
    K = P*H'/(H*P*H'+R);
    x = x + K*(z-H*x);
    disp(K*H);
    P = (1-K*H)*P;
    %disp(P);
    
end



