% author: Nate Sutton 2021
%
% reference: https://www.mathworks.com/matlabcentral/answers/154659-how-to-create-animation-of-matlab-plotting-points-on-a-graph

clear all;
clc;
%x=[-3:0.1:3];
%y=[-3:0.1:3];
time=51; % time steps
t=[0:0.1:(time*.1)];
hFigure = figure;
numberOfFrames = length(t);
% Set up the movie structure.
% Preallocate recalledMovie, which will be an array of structures.
% First get a cell array with all the frames.
allTheFrames = cell(numberOfFrames,1);
vidHeight = 337;%342;
vidWidth = 442;%434;
allTheFrames(:) = {zeros(vidHeight, vidWidth, 3, 'uint8')};
% Next get a cell array with all the colormaps.
allTheColorMaps = cell(numberOfFrames,1);
allTheColorMaps(:) = {zeros(256, 3)};
% Now combine these to make the array of structures.
myMovie = struct('cdata', allTheFrames, 'colormap', allTheColorMaps);
% Create a VideoWriter object to write the video out to a new, different file.
%writerObj = VideoWriter('problem_3.avi');
%open(writerObj);
% Need to change from the default renderer to zbuffer to get it to work right.
% openGL doesn't work and Painters is way too slow.
set(gcf, 'nextplot', 'replacechildren'); 
set(gcf, 'renderer', 'zbuffer');
% [x, y] = meshgrid(-3:.1:3,-3:.1:3);
caxis manual;          % allow subsequent plots to use the same color limits
for frameIndex = 1 : numberOfFrames
  %disp(frameIndex)
  filename = strcat('../output/firing_t',int2str(frameIndex),'.csv');
  [test,delimiterOut]=importdata(filename);
  %z = exp(-(x-t(frameIndex)).^2-(y-t(frameIndex)).^2);
  %test=[1 2 3;4 5 6;7 8 9];
  cla reset;
  % Enlarge figure to full screen.
  %   set(gcf, 'Units', 'Normalized', 'Outerposition', [0, 0, 1, 1]);
  %surf(x,y,z);
  %imagesc(test);
  imagesc(test);
  %imresize(img,[343 434]);
  axis('tight')
  xlabel('neuron position on x axis') 
  ylabel('neuron position on y axis')
  shading interp;
  caxis([0 3.5])
  cb = colorbar;
  set(cb, 'ylim', [0 4]); % set colorbar range
  %zlim([0, 1]);
  caption = sprintf('Grid cell firing amounts, t = %.0f', frameIndex);
  title(caption, 'FontSize', 15);
  %drawnow;
  %shading interp;
  thisFrame = getframe(gcf);
  %lighting phong;
  % Write this frame out to a new video file.
  %size(thisFrame.cdata)
  %writeVideo(writerObj, thisFrame);
  myMovie(frameIndex) = thisFrame;
end
%close(writerObj);
%message = sprintf('Done creating movie\nDo you want to play it?');
%button = questdlg(message, 'Continue?', 'Yes', 'No', 'Yes');
%drawnow;  % Refresh screen to get rid of dialog box remnants.
close(hFigure);
%if strcmpi(button, 'No')
%   return;
%end
%hFigure = figure;
% Enlarge figure to full screen.
% set(gcf, 'Units', 'Normalized', 'Outerposition', [0, 0, 1, 1]);
%title('Playing the movie we created', 'FontSize', 15);
% Get rid of extra set of axes that it makes for some reason.
%axis off;
% Play the movie.
%movie(myMovie);
%uiwait(helpdlg('Done with demo!'));
%close(hFigure);
myMovie(1) = []; % remove first frame causing issues
v = VideoWriter('firing.avi');
open(v)

writeVideo(v,myMovie)
close(v)