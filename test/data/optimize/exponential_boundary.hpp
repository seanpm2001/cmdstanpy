// Code generated by Stan version 2.20.0

#include <stan/model/model_header.hpp>

namespace exponential_boundary_model_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "/Users/mitzi/github/stan-dev/cmdstanpy/test/data/optimize/exponential_boundary.stan");
    reader.add_event(23, 21, "end", "/Users/mitzi/github/stan-dev/cmdstanpy/test/data/optimize/exponential_boundary.stan");
    return reader;
}

class exponential_boundary_model
  : public stan::model::model_base_crtp<exponential_boundary_model> {
private:
        double alpha1;
        double alpha2;
        double beta1;
        double beta2;
        double t1;
        double t2;
public:
    exponential_boundary_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }

    exponential_boundary_model(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "exponential_boundary_model_namespace::exponential_boundary_model";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            // initialize data block variables from context__

            // initialize transformed data variables
            current_statement_begin__ = 2;
            alpha1 = double(0);
            stan::math::fill(alpha1, DUMMY_VAR__);
            stan::math::assign(alpha1,0.2);

            current_statement_begin__ = 3;
            alpha2 = double(0);
            stan::math::fill(alpha2, DUMMY_VAR__);
            stan::math::assign(alpha2,0.2);

            current_statement_begin__ = 4;
            beta1 = double(0);
            stan::math::fill(beta1, DUMMY_VAR__);
            stan::math::assign(beta1,1);

            current_statement_begin__ = 5;
            beta2 = double(0);
            stan::math::fill(beta2, DUMMY_VAR__);
            stan::math::assign(beta2,1);

            current_statement_begin__ = 6;
            t1 = double(0);
            stan::math::fill(t1, DUMMY_VAR__);
            stan::math::assign(t1,0.281152420352801);

            current_statement_begin__ = 7;
            t2 = double(0);
            stan::math::fill(t2, DUMMY_VAR__);
            stan::math::assign(t2,0.164745791682175);

            // execute transformed data statements

            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 10;
            num_params_r__ += 1;
            current_statement_begin__ = 11;
            num_params_r__ += 1;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~exponential_boundary_model() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        current_statement_begin__ = 10;
        if (!(context__.contains_r("lambda1")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable lambda1 missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("lambda1");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "lambda1", "double", context__.to_vec());
        double lambda1(0);
        lambda1 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, lambda1);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable lambda1: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 11;
        if (!(context__.contains_r("lambda2")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable lambda2 missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("lambda2");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "lambda2", "double", context__.to_vec());
        double lambda2(0);
        lambda2 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, lambda2);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable lambda2: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);

            // model parameters
            current_statement_begin__ = 10;
            local_scalar_t__ lambda1;
            (void) lambda1;  // dummy to suppress unused var warning
            if (jacobian__)
                lambda1 = in__.scalar_lb_constrain(0, lp__);
            else
                lambda1 = in__.scalar_lb_constrain(0);

            current_statement_begin__ = 11;
            local_scalar_t__ lambda2;
            (void) lambda2;  // dummy to suppress unused var warning
            if (jacobian__)
                lambda2 = in__.scalar_lb_constrain(0, lp__);
            else
                lambda2 = in__.scalar_lb_constrain(0);

            // transformed parameters
            current_statement_begin__ = 14;
            local_scalar_t__ nu;
            (void) nu;  // dummy to suppress unused var warning
            stan::math::initialize(nu, DUMMY_VAR__);
            stan::math::fill(nu, DUMMY_VAR__);
            stan::math::assign(nu,((lambda1 / 2.0) + lambda2));

            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            current_statement_begin__ = 14;
            if (stan::math::is_uninitialized(nu)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: nu";
                stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable nu: ") + msg__.str()), current_statement_begin__, prog_reader__());
            }

            // model body

            current_statement_begin__ = 17;
            lp_accum__.add(gamma_log<propto__>(lambda1, alpha1, beta1));
            current_statement_begin__ = 18;
            lp_accum__.add(gamma_log<propto__>(lambda2, alpha2, beta2));
            current_statement_begin__ = 19;
            lp_accum__.add(exponential_log<propto__>(t1, lambda1));
            current_statement_begin__ = 20;
            lp_accum__.add(exponential_log<propto__>(t2, nu));

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("lambda1");
        names__.push_back("lambda2");
        names__.push_back("nu");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "exponential_boundary_model_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning

        // read-transform, write parameters
        double lambda1 = in__.scalar_lb_constrain(0);
        vars__.push_back(lambda1);

        double lambda2 = in__.scalar_lb_constrain(0);
        vars__.push_back(lambda2);

        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        if (!include_tparams__ && !include_gqs__) return;

        try {
            // declare and define transformed parameters
            current_statement_begin__ = 14;
            double nu;
            (void) nu;  // dummy to suppress unused var warning
            stan::math::initialize(nu, DUMMY_VAR__);
            stan::math::fill(nu, DUMMY_VAR__);
            stan::math::assign(nu,((lambda1 / 2.0) + lambda2));

            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // write transformed parameters
            if (include_tparams__) {
                vars__.push_back(nu);
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    std::string model_name() const {
        return "exponential_boundary_model";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "lambda1";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "lambda2";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "nu";
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "lambda1";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "lambda2";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "nu";
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }

}; // model

}  // namespace

typedef exponential_boundary_model_namespace::exponential_boundary_model stan_model;

stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}

