import io
import os
import os.path
import sys
import unittest

from cmdstanpy.lib import Model, PosteriorSample
from cmdstanpy.cmds import compile_model, sample

datafiles_path = os.path.join("test", "data")
goodfiles_path = os.path.join(datafiles_path, "runset-good")
badfiles_path = os.path.join(datafiles_path, "runset-bad")


class PostSampleTest(unittest.TestCase):
    def test_postsample_prefab_csv(self):
        column_names = ['lp__','accept_stat__','stepsize__','treedepth__',
                            'n_leapfrog__','divergent__','energy__', 'theta']
        output = os.path.join(datafiles_path, "runset-good")
        csv_files = []
        for i in range(4):
            csv_files.append(os.path.join(output, 'bern-{}.csv'.format(i+1)))
        run = {'draws': 100, 'chains': 4, 'column_names': tuple(column_names)}
        post_sample = PosteriorSample(run, tuple(csv_files))
        self.assertEqual(post_sample.chains,4)
        self.assertEqual(post_sample.draws,100)
        self.assertEqual(post_sample.column_names, tuple(column_names))
        post_sample.sample
        self.assertEqual(post_sample.sample.shape, (100, 4, 8))
        df = post_sample.extract()
        self.assertEqual(df.shape, (400, 8))

    def test_postsample_bad_csv(self):
        csv_files = []
        csv_files = [os.path.join(datafiles_path, 'no-such-sample.csv')]
        run = {'draws': 1, 'chains': 1, 'column_names': []}
        with self.assertRaises(Exception):
            PosteriorSample(run, tuple(csv_files))

    def test_postsample_good(self):
        column_names = ['lp__','accept_stat__','stepsize__','treedepth__',
                            'n_leapfrog__','divergent__','energy__', 'theta']
        stan = os.path.join(datafiles_path, "bernoulli.stan")
        exe = os.path.join(datafiles_path, "bernoulli")
        if not os.path.exists(exe):
            compile_model(stan)
        model = Model(stan, exe_file=exe)
        jdata = os.path.join(datafiles_path, "bernoulli.data.json")
        post_sample = sample(model, data_file=jdata)
        self.assertEqual(post_sample.chains,4)
        self.assertEqual(post_sample.draws,1000)
        self.assertEqual(post_sample.column_names, tuple(column_names))
        post_sample.sample
        self.assertEqual(post_sample.sample.shape,(1000, 4, 8))
        df = post_sample.summary()
        self.assertTrue(df.shape == (2, 9))
        capturedOutput = io.StringIO()
        sys.stdout = capturedOutput
        post_sample.diagnose()
        sys.stdout = sys.__stdout__
        self.assertEqual(capturedOutput.getvalue(), 'No problems detected.\n')

    def test_postsample_diagnose_divergences(self):
        output = os.path.join(datafiles_path, "diagnose-good",
                                  "corr_gauss_depth8-1.csv")
        # TODO - use cmdstan test files instead
        expected = ''.join([
            '424 of 1000 (42%) transitions hit the maximum ',
            'treedepth limit of 8, or 2^8 leapfrog steps. ',
            'Trajectories that are prematurely terminated ',
            'due to this limit will result in slow ',
            'exploration and you should increase the ',
            'limit to ensure optimal performance.\n'])
        run = { 'draws': 10, 'chains': 1, 'column_names': ['a', 'b', 'c']}
        csv_files = tuple([output])
        post_sample = PosteriorSample(run, csv_files)
        capturedOutput = io.StringIO()
        sys.stdout = capturedOutput
        post_sample.diagnose()
        sys.stdout = sys.__stdout__
        self.assertEqual(capturedOutput.getvalue(), expected)

    def test_postsample_big(self):
        sampler_state = ['lp__','accept_stat__','stepsize__','treedepth__',
                             'n_leapfrog__','divergent__','energy__']
        phis = ['phi.{}'.format(str(x+1)) for x in range(2095)]
        column_names = sampler_state + phis
        output = os.path.join(datafiles_path, "runset-big")
        csv_files = []
        for i in range(2):
            csv_files.append(os.path.join(
                output, 'output_icar_nyc_{}.csv'.format(i+1)))
        run = { 'draws': 1000, 'chains': 2, 'column_names': column_names}
        post_sample = PosteriorSample(run, tuple(csv_files))
        post_sample.sample
        self.assertEqual((1000,2,2102), post_sample.sample.shape)
        phis = post_sample.extract(params=['phi'])
        self.assertEqual((2000,2095), phis.shape)
        phi1 = post_sample.extract(params=['phi.1'])
        self.assertEqual((2000,1), phi1.shape)
        phi2095 = post_sample.extract(params=['phi.2095'])
        self.assertEqual((2000,1), phi2095.shape)
        with self.assertRaises(Exception):
            post_sample.extract(params=['phi.2096'])
        with self.assertRaises(Exception):
            post_sample.extract(params=['ph'])


if __name__ == '__main__':
    unittest.main()
