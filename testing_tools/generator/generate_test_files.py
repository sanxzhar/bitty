import os
import subprocess

def create_test_files(num_files=6, lines_per_file=10000):
    # Create test directory if it doesn't exist
    test_dir = os.path.join(os.path.dirname(__file__), 'test_new')
    os.makedirs(test_dir, exist_ok=True)
    
    # Get the path to bitty_inst_generator
    generator_path = os.path.join(os.path.dirname(__file__), 'bitty_inst_generator')
    
    # Generate files
    for i in range(num_files):
        output_file = os.path.join(test_dir, f'program_{i+1}.txt')
        cmd = [generator_path, str(lines_per_file), output_file]
        
        try:
            # Set a different seed for each file
            env = os.environ.copy()
            env['RANDOM_SEED'] = str(i + 1)
            subprocess.run(cmd, check=True, env=env)
            print(f'Created {output_file}')
        except subprocess.CalledProcessError as e:
            print(f'Error creating {output_file}: {e}')
            return

if __name__ == '__main__':
    create_test_files()
