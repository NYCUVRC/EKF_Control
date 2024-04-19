function [varargout]= vdynblksrefconfig(varargin)

%   Copyright 2018-2022 The MathWorks, Inc.

block = varargin{1};
maskMode = varargin{2};
varargout{1} = {};
simStopped = autoblkschecksimstopped(block) && ~(strcmp(get_param(bdroot(block),'SimulationStatus'),'initializing'));
manType = get_param(block,'manType');
vehSys = bdroot(block);

visPath = [vehSys '/Visualization'];
driverpath = [vehSys '/Driver Commands'];
visHandle = getSimulinkBlockHandle(visPath);
driverHandle = getSimulinkBlockHandle(driverpath);
if (driverHandle == -1) || (visHandle == -1)
    disp('Warning: The reference generator subsystem is intended to work only with the example project and model architecture that it ships in. Functionality may therefore be limited if used in another model where the visualization, driver or environment subsystems are no longer available or different locations.')
end
switch maskMode
    case 0
        if simStopped
            switch manType
                case 'Double Lane Change'
                    set_param([block '/Reference Generator'],'LabelModeActiveChoice','0');
                    if visHandle ~= -1
                    set_param([vehSys '/Visualization/Scope Type'],'LabelModeActiveChoice','1');
                    set_param([vehSys '/Visualization/Vehicle XY Plotter'],'LabelModeActiveChoice','1');     
                    else
                        disp('Warning: Visualization subsystem not found. Model scopes and visualizaiton aids may not function as expected.')
                    end
                case 'Increasing Steer'
                    set_param([block '/Reference Generator'],'LabelModeActiveChoice','1');
                    if visHandle ~= -1
                    set_param([vehSys '/Visualization/Scope Type'],'LabelModeActiveChoice','0');
                    set_param([vehSys '/Visualization/Vehicle XY Plotter'],'LabelModeActiveChoice','0');
                    else
                        disp('Warning: Visualization subsystem not found. Model scopes and visualizaiton aids may not function as expected.')
                    end
                case 'Swept Sine'
                    set_param([block '/Reference Generator'],'LabelModeActiveChoice','2');
                    if visHandle ~= -1
                    set_param([vehSys '/Visualization/Scope Type'],'LabelModeActiveChoice','0');
                    set_param([vehSys '/Visualization/Vehicle XY Plotter'],'LabelModeActiveChoice','0');
                    else
                        disp('Warning: Visualization subsystem not found. Model scopes and visualizaiton aids may not function as expected.')
                    end
                case 'Sine with Dwell'
                    set_param([block '/Reference Generator'],'LabelModeActiveChoice','3');   
                    if visHandle ~= -1
                    set_param([vehSys '/Visualization/Scope Type'],'LabelModeActiveChoice','0');
                    set_param([vehSys '/Visualization/Vehicle XY Plotter'],'LabelModeActiveChoice','0');
                    else
                        disp('Warning: Visualization subsystem not found. Model scopes and visualizaiton aids may not function as expected.')
                    end
                case 'Constant Radius'
                    set_param([block '/Reference Generator'],'LabelModeActiveChoice','4');                    
                    if visHandle ~= -1
                    set_param([vehSys '/Visualization/Scope Type'],'LabelModeActiveChoice','2');
                    set_param([vehSys '/Visualization/Vehicle XY Plotter'],'LabelModeActiveChoice','1');
                    else
                        disp('Warning: Visualization subsystem not found. Model scopes and visualizaiton aids may not function as expected.')
                    end
                case 'Fishhook'
                    set_param([block '/Reference Generator'],'LabelModeActiveChoice','5');
                    if visHandle ~= -1
                    set_param([vehSys '/Visualization/Scope Type'],'LabelModeActiveChoice','0');
                    set_param([vehSys '/Visualization/Vehicle XY Plotter'],'LabelModeActiveChoice','0');
                    else
                        disp('Warning: Visualization subsystem not found. Model scopes and visualizaiton aids may not function as expected.')
                    end
                otherwise
            end
        end
    case 1
        manOverride = strcmp(get_param(block,'manOverride'),'on');
        switch manType
            case 'Double Lane Change'
                autoblksenableparameters(block, [], [],{'DLCGroup'},{'ISGroup';'CRGroup';'SSGroup';'SDGroup';'FHGroup'});
                autoblksenableparameters(block,[],{'steerDir'},[],[],true);
                if simStopped && manOverride && (driverHandle~=-1)
                    set_param([vehSys '/Driver Commands'],'driverType','Longitudinal Driver');
                    set_param([vehSys '/Driver Commands'],'driverType','Predictive Driver');
                    set_param(block,'simTime','25');
                end
            case 'Increasing Steer'
                autoblksenableparameters(block, [], [],{'ISGroup'},{'DLCGroup';'CRGroup';'SSGroup';'SDGroup';'FHGroup'});
                autoblksenableparameters(block,{'steerDir'},[],[],[],true);
                if simStopped && manOverride && (driverHandle~=-1)
                    set_param([vehSys '/Driver Commands'],'driverType','Longitudinal Driver');
                    set_param(block,'simTime','60');                    
                end
            case 'Swept Sine'
                autoblksenableparameters(block, [], [],{'SSGroup'},{'ISGroup';'DLCGroup';'CRGroup';'SDGroup';'FHGroup'});
                autoblksenableparameters(block,[],{'steerDir'},[],[],true);
                if simStopped && manOverride && (driverHandle~=-1)
                    set_param([vehSys '/Driver Commands'],'driverType','Longitudinal Driver');
                    set_param(block,'simTime','40');
                end
            case 'Sine with Dwell'
                autoblksenableparameters(block, [], [],{'SDGroup'},{'ISGroup';'DLCGroup';'CRGroup';'SSGroup';'FHGroup'});
                autoblksenableparameters(block,{'steerDir'},[],[],[],true);
                if simStopped && manOverride && (driverHandle~=-1)
                    set_param([vehSys '/Driver Commands'],'driverType','Longitudinal Driver');
                    set_param(block,'simTime','25');                    
                end
            case 'Constant Radius'
                autoblksenableparameters(block, [], [],{'CRGroup'},{'DLCGroup';'ISGroup';'SSGroup';'SDGroup';'FHGroup'});
                autoblksenableparameters(block,{'steerDir'},[],[],[],true);
                if simStopped && manOverride  && (driverHandle~=-1)                 
                    currDriverMode = get_param([vehSys '/Driver Commands'],'driverType');
                    if ~strcmp(currDriverMode,'Predictive Driver') && ~strcmp('updating',get_param(bdroot(block),'SimulationStatus'))
                        set_param([vehSys '/Driver Commands'],'driverType','Predictive Stanley Driver');                    
                    end
                    set_param(block,'simTime','60');
                end
            case 'Fishhook'
                autoblksenableparameters(block, [], [],{'FHGroup'},{'ISGroup';'DLCGroup';'CRGroup';'SDGroup';'SSGroup'});
                autoblksenableparameters(block,{'steerDir'},[],[],[],true);
                pFdbkChk = get_param(block,'pFdbk');
                if strcmp(pFdbkChk,'off')
                    autoblksenableparameters(block,{'tDwell1'},{'pZero'},[],[],'false')
                else
                    autoblksenableparameters(block,{'pZero'},{'tDwell1'},[],[],'false')
                end
                if simStopped && manOverride && (driverHandle~=-1)
                    set_param([vehSys '/Driver Commands'],'driverType','Longitudinal Driver');
                    set_param(block,'simTime','40');
                end    
            otherwise
        end
        if simStopped && manOverride && ~strcmp(get_param(block,'prevType'),manType)
            update3DScene(block,manType);
            [~] = vdynblksmdlWSconfig(block,false);
        end
        set_param(block,'prevType',manType)
    case 2
        simStopTime = get_param(block,'simTime');
        set_param(vehSys,'StopTime',simStopTime);
end
end
function update3DScene(block,manType)
sim3DBlkPath = block;
if strcmp(manType,'Double Lane Change')
    set_param(sim3DBlkPath,'SceneDesc','Double lane change');
else
    set_param(sim3DBlkPath,'SceneDesc','Open surface');
end
end