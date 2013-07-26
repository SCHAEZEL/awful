function au_sparse_test()

% au_SPARSE_TEST Test routine for mex file au_sparse

% Author: Andrew Fitzgibbon <awf@robots.ox.ac.uk>
% Date: 22 Jul 02

Ms = sparse([1 2 7], [7 8 11], [1 2 3]);

Ma = au_sparse(int32([1 2 7]), int32([7 8 11]), double([1 2 3]));

test('simple sparse', Ma, Ms);

Ma = au_sparse(int32([1 2 7 7]), int32([7 8 11 11]), [1 2 3 1]);
Ms = sparse([1 2 7 7], [7 8 11 11], [1 2 3 1]);
test('duplicate entries', Ma,Ms);

% this should fail
try
  Ma = au_sparse(int32([1 7 2]), int32([7 11 8]), double([1 3 2]))
  disp('au_sparse_test: nonmonotonic columns did not fail as it ought to: BAD')
catch
  disp('au_sparse_test: nonmonotonic columns failed as it ought to: ok')
end

% this should fail
try
  Ma = au_sparse(int32([1 2 1 4 4 4 ]), int32([1 1 1 12 12 12]), double([1 2 3 5 7 11]))
  disp('au_sparse_test: nonmonotonic rows within columns did not fail as it ought to: BAD')
catch
  disp('au_sparse_test: nonmonotonic rows within columns failed as it ought to: ok')
end

% this should fail
try
  Ma = au_sparse(int32([1 2 3 4 5 4 ]), int32([1 1 1 12 12 12]), double([1 2 3 5 7 11]))
  disp('au_sparse_test: nonmonotonic rows within columns did not fail as it ought to: BAD')
catch
  disp('au_sparse_test: nonmonotonic rows within columns failed as it ought to: ok')
end

function test(msg, Ma, Ms)
EQUAL = full(all(all(Ma == Ms)));
if EQUAL
  fprintf('au_sparse_test: checking %s: ok\n', msg);
else
  fprintf('au_sparse_test: checking %s: FAILED\n', msg);
  Ma
  Ms
end
